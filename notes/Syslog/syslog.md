In computing, `syslog` is a standard for message logging. 
It allows separation of the software that generates messages, the system that stores them, and the software that reports and analyzes them.
Each message is labeled with a facility code, indicating the type of system generating the message, and is assigned a severity level.

Computer system designers may use syslog for system mgmt. and security auditing as well as general infoormational, analysis, and debugging messages.
A wide variety of devices, such as printers, router, and message recievers across many platforms use the syslog standard.
This permits the consolidation of logging data from different types of systems in a central repo.
Implementation of syslog exists in many systems.

When operating over a network, syslog uses a client-server architecture where a `syslog server` listens for and logs messages coming from clients.

- A variety of implementations also exists on other OS and its commonly found in network devices, such as routers.

## Message components

The information provided by the originator of a syslog message includes the facility code and the severity level. The syslog software adds information to the information header before passing the entry to the syslog receiver. Such components include an originator process ID, a timestamp, and the hostname or IP address of the device.

### Facility

A facility code is used to specify the type of system that is logging the message. Messages with different facilities may be handled differently. The list of facilities available is described by the standard: 

Facility code	Keyword	                Description

0	                kern	        Kernel messages
1	                user	        User-level messages
2	                mail	        Mail system
3	               daemon	        System daemons
4	                auth	        Security/authentication messages
5	               syslog	        Messages generated internally by syslogd
6	                lpr	            Line printer subsystem
7	                news	        Network news subsystem
8	                uucp	        UUCP subsystem
9	                cron	        Cron subsystem
10	               authpriv	       Security/authentication messages
11	                ftp	            FTP daemon
12	                ntp	            NTP subsystem
13	                security	    Log audit
14	                console	        Log alert
15	              solaris-cron	   Scheduling daemon
16–23	        local0 – local7	    Locally used facilities


The mapping between facility code and keyword is not uniform in different operating systems and syslog implementations.







