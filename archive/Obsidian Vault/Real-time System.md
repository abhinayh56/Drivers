## Software requirements
1. Install Ubuntu22.04 with kernel 5.15.0
2. RT Linux kernel
Install real-time Linux kernel (*5.15.0-1083-realtime*)

Check the kernel version with follwing command
```
uname -r
```

Check kernel and Linux version with following command
```
uname -a
```

3. Look for PREEMPT_RT or PREEMPT in kernel config.
```
CONFIG_PREEMPT_RT=y
```
Verify using following command
```
grep PREEMPT /boot/config-$(uname -r)
```

- Run the program as root. Only root or process with CAP_SYS_NICE can use real-time scheduling
```
sudo ./realtime_app
```

- Allow non-root real-time privileges
Add limits in */etc/security/limits.conf*
```
<username> soft rtprio 99
<username> hard rtprio 99
```
After setting the priority. Relog or reboot the system.

- Check PAM config for limits. Ensure */etc/pam.d/common-session* contains
```
session required pam_limits.so
```

- CPU Isolation (For RT Threads only)
Edit GRUB
```
sudo nano /etc/default/grub
```

Add
```
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash isolcpus=2 nohz_full=2 rcu_nocbs=2"
```

Then update and reboot grub
```
sudo update-grub
sudo reboot
```

- Pin network / USB IRQs away from real-time cores using *tuna* or *irqbalance*

### Kernel-level Configuration
Verify PREEMPT_RT kernel patch

1. Check for real-time kernel
```
uname -r
```

2. Check for real-time kernel & OS distribution
```
uname -a
```

3. Check if kernel is fully preemptable
```
grep PREEMPT /boot/config-$(uname -r)
```

4. Verify for the following output
```
CONFIG_PREEMPT_RT=y
```

### GRUB boot Parameters
CPU core isolation for RT task.
```
sudo /etc/default/grub
```

Edit grub file by adding following parameters
```
GRUB_CMDLINE_LINUX_DEFAULT=”quiet splash isolcpus=4,5 nohz_full=4,5 rcu_nocbs=4,5 irqaffinity=0-3”
```

Update GRUB
```
sudo update-grub
```

Reboot the system
```
reboot
```
### CPU Configuration
Disable scaling

### Interrupts & IRQ Tuning

### Memory

### Timers & Sleep

### Threads & Scheduling

### File system & Logging

### Networking

### Monitoring & Debugging

### Memory Management

### Permission & Limits

### Application Design Practices

### Recommendation for IgH EtherCAT Master



  

# Real-Time Linux Setup
This guide is tailored for setting up a deterministic real-time environment using the PREEMPT_RT kernel, with specific notes for IgH EtherCAT Master 1.6, Linux Kernel 5.15, and i210 NIC on Ubuntu 22.04 LTS.

---
## 1. Kernel-level Configuration
1. Install a compatible PREEMPT_RT kernel patch (e.g., `linux-image-5.15.0-rt`).
2. Disable unneeded kernel modules.
3. Verify PREEMPT_RT kernel patch using following steps
4. Check for real-time kernel
```
uname -r
```
5. Check for real-time kernel & OS distribution
```
uname -a
```
6. Check if kernel is fully preemptable by verifying the `CONFIG_PREEMPT_RT=y` in the output
```
grep PREEMPT /boot/config-$(uname -r)
```
---
## 2. GRUB Boot Parameters
CPU core isolation for RT task.
1. Modify `/etc/default/grub` by adding following lines
```
sudo nano /etc/default/grub
```
Edit grub file by adding following parameters
```
GRUB_CMDLINE_LINUX_DEFAULT=”quiet splash isolcpus=4,5 nohz_full=4,5 rcu_nocbs=4,5 irqaffinity=0-3”


```

Update GRUB
```
sudo update-grub
```

Reboot the system
```
reboot
```


```
Add to `/etc/default/grub`:
```
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash nohz_full=1-3 rcu_nocbs=1-3 isolcpus=1-3 intel_pstate=disable mce=off audit=0 nmi_watchdog=0 irqaffinity=0 loglevel=3"
```

- Isolate CPUs using `nohz_full`, `isolcpus`, `rcu_nocbs`.
Then run:
```
sudo update-grub
```
---
## 3. CPU Configuration
- Isolate real-time cores using `isolcpus`.
- Pin real-time tasks to isolated cores.
- Avoid system services running on isolated cores (`ps`, `htop`, `tuna`).

7. Set CPU frequency governor to `performance`:
```
echo performance | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
```

```
echo performance | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
```

---
## 4. Interrupts & IRQ Tuning
- Use `tuna` or `irqbalance` manually to offload IRQs from RT cores.
- Set IRQ priorities:
```
sudo chrt -f -p 90 <irq_thread_pid>
```
---
## 5. Memory
- Lock memory in real-time tasks:
```
mlockall(MCL_CURRENT | MCL_FUTURE);
```

- Use `tmpfs` for /tmp and logging.
- Disable Transparent Huge Pages (THP):
```
echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled
```
---
## 6. Timers & Sleep
- Use `clock_nanosleep()` or POSIX timers.
- Avoid `usleep()` or `nanosleep()` in real-time paths.
---
## 7. Threads & Scheduling
- Use `SCHED_FIFO` or `SCHED_RR` policies.
- Avoid thread over-subscription on isolated CPUs.
- Assign priority carefully (e.g., 80–99).
---
## 8. File System & Logging
- Use minimal logging during RT tasks.
- Prefer `tmpfs` or in-memory log buffers.
- Avoid log rotation during RT cycles.
---
## 9. Networking
- Disable offloading features:
```
sudo ethtool -K eth0 tso off gso off gro off rx off tx off
```

- Use real-time NICs (Intel i210, i350).
- Bind NIC IRQs to isolated CPU.
---
## 10. Monitoring & Debugging
- Use `cyclictest` to measure latency.
- Use `ftrace`, `trace-cmd`, `perf` for debugging.
- Check logs for missed deadlines.
---
## 11. Memory Management
- Lock all memory.
- Use static memory allocation.
- Minimize dynamic memory in RT code paths.
---
## 12. Permission & Limits
Edit `/etc/security/limits.conf`:
```
@realtime   -  rtprio     99
@realtime   -  memlock    unlimited
@realtime   -  nice       -20
```

Ensure user is in `realtime` group.

---
## 13. Application Design Practices
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
## Appendix: IgH EtherCAT Master 1.6 + PREEMPT_RT 5.15 + i210 on Ubuntu 22.04

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
