This guide is tailored for setting up a deterministic real-time environment using the PREEMPT_RT kernel, with specific notes for IgH EtherCAT Master 1.6, Linux Kernel 5.15, and i210 NIC on Ubuntu 22.04 LTS.

---
## 1. Kernel-level Configuration
1. Install a compatible PREEMPT_RT kernel patch (e.g., `linux-image-5.15.0-rt`).
2. Disable unneeded kernel modules.
3. Verify PREEMPT_RT real-time kernel patch using following steps
```
uname -r
```

4. Check for real-time kernel & OS distribution
```
uname -a
```

5. Check if kernel is fully preemptable by verifying the `CONFIG_PREEMPT_RT=y` in the output
```
grep PREEMPT /boot/config-$(uname -r)
```
---
## 2. GRUB Boot Parameters
Isolate CPU core using `isolcpus`, `nohz_full`, `rcu_nocbs`.
- `isocpus`: Prevents the kernel scheduler from assigning tasks to specific CPUs. Used for real-time or dedicated CPU use.
- `nohz_full`: Enables full "tickless" operation on specified CPUs -- reducing timer interruptions for real-time workloads.
- `rcu_nocbs`: Moves RCU callbacks for specified CPUs to kernel threads to reduce jitter.
- `irqaffinity`: Specifies which CPUs are allowed to handle interrupts.

1. Modify `/etc/default/grub`
```
sudo nano /etc/default/grub
```

2. Modify parameters of `GRUB_CMDLINE_LINUX_DEFAULT` as following
```
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash isolcpus=4,5 nohz_full=4,5 rcu_nocbs=4,5 irqaffinity=0-3 intel_pstate=disable mce=off audit=0 nmi_watchdog=0 loglevel=3"
```

3. Update GRUB
```
sudo update-grub
```

4. Reboot the system for changes to take effect
```
reboot
```

5. Check if GRUB was updated successfully
Updating GRUB regenerates the GRUB configuration file (`/boot/grub/grub.cfg`) with new changes. Check the actual GRUB config file
```
grep "linux" /boot/grub/grub.cfg | grep -v "^#"
```

Look for lines like
```
linux /boot/vmlinuz-... root=... quiet splash isolcpus=4,5
```

This will confirm that your parameters (e.g., `quiet`, `splash`, `isolcpus=4,5`) are present in the boot entries.

Check the current kernel parameters (runtime verification). Once the system is booted, you can verify which kernel parameters are in effect with. Check the current boot parameters to ensure they were applied:
```
cat /proc/cmdline
```
Example output:
```
BOOT_IMAGE=/boot/vmlinuz-... root=... quiet splash `isolcpus=4,5`
```
This confirms what kernel parameters were used during boot.

Verify functional changes (optional)
If you changed a kernel behavior (e.g., isolcpus=4,5), verify the effect directly:
```
cat /proc/sys/kernel/ostype
cat /proc/sys/kernel/osrelease
cat /proc/sys/kernel/version
cat /proc/sys/kernel/hostname
```

Verify `isolcpus`
```
cat /sys/devices/system/cpu/isolated
```
Also try using 
```
sudo dmesg | grep isolcpus
```

Verify `nohz_full`
```
cat /sys/devices/system/cpu/nohz_full
```
Also try using
```
dmesg | grep -i nohz_full
```

Verify `rcu_nocbs`
```
sudo dmesg | grep rcu_nocbs
```
Also try using (Shows a CPU mask where RCU callbacks are offloaded)
```
sudo cat /sys/kernel/rcu_nocb_mask
```

Verify `irqaffinity`
```
grep . /proc/irq/*/smp_affinity_list
```
This shows the CPUs assigned to each IRQ line. You should **not see your isolated CPUs** here if the parameter is effective.
To verify dynamically:
```
cat /proc/interrupts
```

```
cat /sys/devices/system/cpu/online
```

```
cat /sys/devices/system/cpu/offline
```

```
cat /sys/devices/system/cpu/present
```

```
cat /sys/devices/system/cpu/possible
```

---
## 3. CPU Configuration
To **set the CPU frequency governor** on a Linux system, follow the steps below. This allows you to control how your CPU scales frequency — e.g., for performance, power saving, or real-time determinism.
Set CPU frequency governor to `performance`:
```
echo performance | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
```

Set governor to performance
```
cpupower frequency-set -g performance
```

1. Pin real-time tasks to isolated cores.
2. Disable scaling (cpu frequencies + performance governor). this prevents frequency changes.
3. Avoid system services running on isolated cores (`ps`, `htop`, `tuna`).
4. Disable hyper-threading in BIOS to avoid core contention.
5. Disable turbo-boost
```
echo 1 | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo
```
7. Use `cset shield` or `taskset` to isolate CPUs for RT tasks.
8. `cset shield --cpu=2,3` for RT code exclusive CPUs.
---
## 4. Interrupts & IRQ Tuning
- View IRQs using 
```
cat /proc/interrupts
```
- View IRQ CPU affinity in `/proc/irq/*/smp_affinity`. Keep IRQs off RT CPUs.
- Disable irqbalance `systemctl stop irqbalance`
- Disable unused peripherals. Disable via `systemctl` or `BIOS`. It is to reduce ISR noise.
- Use `tuna` or `irqbalance` manually to offload IRQs from RT cores.
- Set IRQ priorities:
```
sudo chrt -f -p 90 <irq_thread_pid>
```
---
## 5. Memory Management
- Lock memory in real-time tasks with `mlockall(MCL_CURRENT | MCL_FUTURE)`
- Set `ulimit -I unlimited` in `/etc/security/limits.conf`
- Above two are to avoid page faults
- Pre-allocate all needed memory in init and avoid malloc/free during runtime. This is done to allocate buffers early.
- Disable swap `sudo wsapoff -a`
- Use `tmpfs` for /tmp and logging.
- Disable Transparent Huge Pages (THP):
```
echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled
```
---
## 6. Timers & Sleep
- Timers and sleep parameters are crucial for deterministic sleeping.
- Use high-res timers `clock_nanosleep(CLOCK_MONITONIC, ...)`
- Use `clock_nanosleep()` or POSIX timers.
- Avoid `sleep()`, `usleep()` or `nanosleep()` in real-time paths.
- Use `timerfd_create()` for predictable event timing.
---
## 7. Threads & Scheduling
- Use `SCHED_FIFO` or `SCHED_RR` policies with `pthread_setschedparam()`. RT scheduling ensure priority execution.
- Lock memory using `mlockall()` and `ulimit -I unlimited`
- Run with `chrt -f 80 ./your_app`. This sets priority, overrides non-rt processes.
- Pin threads with `taskset` or `pthread_set_affinity_np()`
- Avoid thread over-subscription on isolated CPUs.
- Assign priority carefully (e.g., 80–99).
---
## 8. File System & Logging
- Use minimal logging during RT tasks.
- Prefer `tmpfs` or in-memory log buffers.
- Avoid log rotation during RT cycles.
- Avoid disk I/O in RT threads.
- Use `tmpfs` for temporary data and logs
- Disable logging wherever possible.
- Avoid logging.
- All above points are to minimize FS I/O, to avoid I/O latency.
---
## 9. Networking
- Disable NMI watchdog to avoid unwanted interrupts
```
echo 0 > /proc/sys/kernel/nmi_watchdog
```
- Disable offloading features:
```
sudo ethtool -K eth0 tso off gso off gro off rx off tx off
```
- Use real-time capableNICs and drivers (Intel i210, i350). It is for RT networking. Use DPDK / tuned NIC drivers to bypass the kernel network stack.
- Bind NIC IRQs to isolated CPU.
- Use DPDK/XDP for zero-copy networking if required.
---
## 10. Monitoring & Debugging
- Use `cyclictest` to measure latency.
- Use `ftrace`, `trace-cmd`, `perf` for debugging.
- Check logs for missed deadlines.
- Measure latency and verify RT behavior using `cyclictest --smp --priority=80 -m -n -i 1000 -d 10`
- Use `htop`, `ps -eLo pid,psr,cls,rtprio,pri,nice,cmd`
- Use tools such as `latencytop`, `ftrace`, `perf`, `trace-cmd`
- Tune as needed, analyze cyclictest results, optimize latency sources.
---
## 11. Memory Management
- Lock all memory.
- Use static memory allocation.
- Minimize dynamic memory in RT code paths.
---
## 12. Permission & Limits
Modify `/etc/security/limits.conf`:
```
@realtime   -  rtprio     99
@realtime   -  memlock    unlimited
@realtime   -  nice       -20
```

```
<user>    hard    rtprio    99
<user>    soft    rtprio    99
<user>    hard    memlock    unlimited
<user>    soft    memlock    unlimited
```
Ensure user is in `realtime` group.
Also ensure `/etc/pam.d/common-session` includes `session required pam_limits.so`

---
## 13. Application Design Practices
- Use lock-free designs.
- Avoid signals in RT threads
- Keep runtime deterministic, use static memory, avoid dynamic linking.
- Minimize malloc/free in real-time paths.
- Avoid blocking system calls.
- Use bounded queues and lock-free data structures.
- Use CPU affinity and memory pinning.
---
## 14. Thermal & Power Management
- Disable `intel_pstate`, use fixed frequencies.
- Disable `thermald`, `cpupower`, and CPU sleep states (C-states).
---
## 15. Watchdog & Background Services
- Disable or stop:
  - `irqbalance`
  - `cron`, `anacron`
  - `snapd`
  - `thermald`
  - `unattended-upgrades`
---
## 16. RT-Aware Systemd Services
Set in systemd unit files:
```
CPUAffinity=2 3
Nice=-20
IOSchedulingClass=real-time
```
---
## 17. PCI & NUMA Optimization
- Use `lspci -vv` and `setpci` for tuning PCI latency timers.
- Pin memory and threads to same NUMA node.
---
## Appendix: Recommendations for IgH EtherCAT Master
- Use Intel NICs (i210 recommended), disable offloads: `ethtool -K eth0 tx off rx off gso off gro off tso off`
- Disable NetworkManager for real-time NIC.
- Use IRQ affinity to assign NIC interrupts to non-RT CPUs.
- Ensure the NIC driver supports real-time (avoid r8169).
- BIOS:
	- Disable C-States (C1E, C6, etc.)
	- Disable Hyper-threading
	- Enable HPET if available
- GRUB:
	- isolcpus, rcu_nocbs, irqaffinity as above
- CPU:
	- Shield CPUs for EtherCAT threads using `cset`
	- Pin EtherCAT threads to isolate CPUs
- Compile the IgH driver with `PREEMPT_RT` support
- Use `cyclictest` and `ethercat master` diagnostics to validate
### Build Instructions
```
sudo apt install build-essential cmake libtool autoconf git
git clone https://gitlab.com/etherlab.org/ethercat.git
cd ethercat
./bootstrap
./configure --enable-igb
make -j$(nproc)
sudo make install
```
### Kernel Notes
- Works with PREEMPT_RT kernel 5.15.x
- Ensure you are not using Xenomai/RTAI
### NIC Notes (i210)
- i210 is fully compatible with IgH `igb` driver
- Disable default kernel `igb` before loading IgH driver:
```
sudo modprobe -r igb
```
### Network Configuration
- Disable offloads with `ethtool`
- Assign IRQ affinity to isolated CPU
- Use `ethercat` tool to check slave timing
### BIOS Settings
- Disable hyper-threading
- Disable C-states (set to C1 or C0 only)
- Enable HPET if supported
### GRUB Settings for Real-Time
```
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash nohz_full=2-3 rcu_nocbs=2-3 isolcpus=2-3 intel_pstate=disable mce=off audit=0 nmi_watchdog=0 irqaffinity=0"
```
### Testing & Monitoring
- Use `ethercat slaves`, `ethercat timing`
- Use `cyclictest` with isolated CPUs to benchmark latency
---
