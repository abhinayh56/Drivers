
# Requirements
- Hardware requirements
- Software requirements

# Installation
TODO

# Command line interface
TODO

# Application interface
TODO

# Application development
## Project organization
TODO

## Project build files
TODO

## Project execution file
TODO

# Realtime
TODO

# Xtras
TODO

### Flow chart of IGH EtherCAT master operation sequence till pdo communication in cyclic mode

1. Start master
```
master = ecrt_request_master(0);
```
2. Create domain
```
ecrt_master_create_domain(master);
```
3. Configure slave_i; i = 0, 1, ...
```
sc_rfid = ecrt_master_slave_config(master_, rfid_alias_pos, rfid_vendorid_prod_code))
```
4. Create PDO configuration for slave_i; i = 0, 1, ...
```
ecrt_slave_config_pdos(sc_rfid, EC_END, rfid_syncs)
```
5. Register group of PDOs to a domain
```
ecrt_domain_reg_pdo_entry_list(domain1, domain1_regs)
```
6. Finishes configuration and activates master
```
ecrt_master_activate(master)
```
7. Get pointer to domain process data
```
domain1_pd = ecrt_domain_data(domain1)
```
8. Cyclic task
	1. Fetches received frames from the hardware and processes the datagrams
	```
	ecrt_master_receive(master);
	```
	2. Determines the states of the domain's datagrams
	```
	ecrt_domain_process(domain1);
	```
	3. Reads the state of a domain
	```
	ec_domain_state_t ds;
	ecrt_domain_state(domain1, &ds);
	domain1_state = ds;
	```
	4. Read process data
	5. Publish process data
	6. Subscribe process data
	7. Write process data
	8. Send process data
	```
	ecrt_domain_queue(domain1);
	ecrt_master_send(master);
	```
	9. Check master state
	```
	ec_master_state_t ms;
	ecrt_master_state(master, &ms);
	master_state = ms;
	```
	10. Check of slave_i; i = 0, 1, ...
	```
	ec_slave_config_state_t s;
	ecrt_slave_config_state(sc_my_slave, &s);
	my_slave_state = s;
	```
9. Stop master
```
ecrt_release_master(master)
```

## Slave cyclic task

Cyclic task
1. monitor_status
2. transfer_tx_pdo
3. process_tx_pdo
4. publish_data
5. subscribe_data
6. process_rx_pdo
7. transfer_rx_pdo


# EtherCAT_layer.cpp
1. Include libraries
	1. EtherCAT master
		```
		#include "EtherCAT_master/EtherCAT_master.h"
		```
	2. EtherCAT slaves
		```
		#include "Slaves/EtherCAT_slave_1.h"
		#include "Slaves/EtherCAT_slave_2.h"
		```
2. Create objects
	1. EtherCAT master
		```
		EtherCAT_master ec_master;
		```
	2. EtherCAT slaves
		```
		EtherCAT_slave_1 slave_1;
		EtherCAT_slave_2 slave_2;
		```
3. Add slaves to master
	```
	ec_master.add_slave(&slave_1);
	ec_master.add_slave(&slave_2);
	```
4. Start master
	```
	ec_master.start();
	```
5. Configure master
	```
	ec_master.config();
	```
6. Run cyclic task
	```
	while (ec_master.is_running())
	{
		ec_master.cyclic_task();
		usleep(4000);
	}
	```
## Complete program is
```
	#include <unistd.h>
	#include <iostream>
	#include "EtherCAT_master/EtherCAT_master.h"
	#include "Slaves/EtherCAT_slave_1.h"
	#include "Slaves/EtherCAT_slave_2.h"
	
	EtherCAT_master ec_master;
	
	EtherCAT_slave_1 slave_1;
	EtherCAT_slave_2 slave_2;
	
	int main()
	{
		ec_master.add_slave(&slave_1);
		ec_master.add_slave(&slave_2);
		
		ec_master.start();
		
		ec_master.config();
		
		while (ec_master.is_running())
		{
			ec_master.cyclic_task();
			usleep(4000);
		}
		
		return 0;
	}
```
# EtherCAT_master.cpp, .h
1. Include libraries
	1. IGH Ethercat master
		```
		#include <ecrt.h>
		```
	2. Data transfer abstract class
		```
		#include "Data_transfer.h"
		```
	3. EtherCAT slave base class
		```
		#include "../EtherCAT_slave_base/EtherCAT_slave_base.h"
		```
# EtherCAT_slave_x.cpp, .h




# Include Hardware Abstraction Layer
1. Separate library for hardware modules such as EtherCAT slaves. It must not contain any logic for user control.
2. It should just share data with other program

# Class Inheritance
1. Data_transfer
	1. Ec_master
	2. Ec_slave_base
		1. Ec_slave_base_coupler
		2. Ec_slave_base_junction
		3. Ec_slave_base_motor_drive
			1. Ec_slave_ingenia_denali
			2. Ec_slave_ingenia_capitan
			3. Ec_slave_ingenia_technosoft
			4. Ec_slave_elmo
			5. Ec_slave_zero_error
			6. Ec_slave_mact
		4. Ec_slave_base_digital_in
			1. Ec_slave_el_1008
		5. Ec_slave_base_digital_out
			1. Ec_slave_el_2008
		6. Ec_slave_base_analog_in
			1. Ec_slave_el_3024
		7. Ec_slave_base_rs232
			1. Ec_slave_el_6002
		8. Ec_slave_base_rfid
		9. Ec_slave_base_enc_brk_ctrl
		10. Ec_slave_base_scc_control_module

# Run sudo without password

### Use `system()` in C++ to invoke the terminal command
```
#include <cstdlib>

int main() {
    int result = system("sudo /etc/init.d/ethercat start");
    if (result == 0) {
        // Success
    } else {
        // Failed
    }
    return 0;
}
```

⚠️ **Note**: This will prompt for a sudo password unless you've set up passwordless sudo for this command.
### Configure **Passwordless Sudo**
1. Run:
```
sudo visudo
```

2. Add the following line (replace `username` with your actual username):
```
username ALL=(ALL) NOPASSWD: /etc/init.d/ethercat
```

Now your C++ `system()` call will not prompt for a password.

# Changing EtherCAT init file

Modify file /etc/init.d/ethercat using root command for message display using echo.
```
sudo gedit /etc/init.d/ethercat
```

```
#!/bin/sh

#------------------------------------------------------------------------------
#
#  Init script for EtherCAT
#
#  Copyright (C) 2006-2021  Florian Pose, Ingenieurgemeinschaft IgH
#
#  This file is part of the IgH EtherCAT Master.
#
#  The IgH EtherCAT Master is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License version 2, as
#  published by the Free Software Foundation.
#
#  The IgH EtherCAT Master is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
#  Public License for more details.
#
#  You should have received a copy of the GNU General Public License along
#  with the IgH EtherCAT Master; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#
#
#  vim: expandtab
#
#------------------------------------------------------------------------------

### BEGIN INIT INFO
# Provides:          ethercat
# Required-Start:    $local_fs $syslog $network
# Should-Start:      $time ntp
# Required-Stop:     $local_fs $syslog $network
# Should-Stop:       $time ntp
# Default-Start:     3 5
# Default-Stop:      0 1 2 6
# Short-Description: EtherCAT master
# Description:       EtherCAT master 1.6.3
### END INIT INFO

#------------------------------------------------------------------------------

ETHERCATCTL="/usr/local/etherlab/sbin/ethercatctl -c /usr/local/etherlab/etc/sysconfig/ethercat"

#------------------------------------------------------------------------------

exit_success() {
    if [ -r /etc/rc.status ]; then
        rc_reset
        rc_status -v
        rc_exit
    else
        echo " done"
        exit 0
    fi
}

#------------------------------------------------------------------------------

exit_fail() {
    if [ -r /etc/rc.status ]; then
        rc_failed
        rc_status -v
        rc_exit
    else
        echo " failed"
        exit 1
    fi
}

#------------------------------------------------------------------------------

if [ -r /etc/rc.status ]; then
    . /etc/rc.status
    rc_reset
fi

case "${1}" in

start)
    echo -n "INFO   : EC_MASTER -> Starting EtherCAT master 1.6.3 "

    if $ETHERCATCTL start; then
        exit_success
    else
        exit_fail
    fi
    ;;

stop)
    echo -n "INFO   : EC_MASTER -> Shutting down EtherCAT master 1.6.3 "

    if $ETHERCATCTL stop; then
        exit_success
    else
        exit_fail
    fi
    ;;

restart)
    $0 stop || exit 1
    sleep 1
    $0 start
    ;;

status)
    $ETHERCATCTL status
    exit $?
    ;;

*)
    echo "ERROR  : EC_MASTER -> USAGE: $0 {start|stop|restart|status}"
    ;;

esac

if [ -r /etc/rc.status ]; then
    rc_exit
else
    exit 1
fi

#------------------------------------------------------------------------------
```