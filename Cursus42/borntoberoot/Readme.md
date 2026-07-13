*This project has been created as part of the 42 curriculum by jrecio-t.*

# Born2BeRoot

## Table of Contents

- [Description](#description)
- [Project Design](#project-design)
- [Instructions](#instructions)
- [Monitoring Script](#monitoring-script)
- [Resources](#resources)

---

# Description

Born2BeRoot is a system administration project from the 42 curriculum. Its objective is to install and configure a secure Linux server inside a virtual machine while applying good security and administration practices.

The project includes:

- Debian installation without a graphical interface.
- Encrypted partitions using **LUKS** and **LVM**.
- Secure remote access with **OpenSSH**.
- Firewall configuration with **UFW**.
- Password and sudo security policies.
- Automatic system monitoring using **cron**.

## Operating System Choice

### Debian vs Rocky Linux

| Debian | Rocky Linux |
|---------|-------------|
| Community maintained | Enterprise (RHEL compatible) |
| Uses APT | Uses DNF |
| Excellent documentation | Enterprise-oriented |
| Stable packages | Long enterprise support |

Debian was chosen because it is stable, well documented, simple to configure and officially supported by the project.

### AppArmor vs SELinux

| AppArmor | SELinux |
|-----------|----------|
| Path-based | Label-based |
| Easier to configure | More powerful but more complex |
| Native on Debian | Native on Rocky/RHEL |

AppArmor was selected because it is integrated into Debian and provides a good balance between security and simplicity.

### UFW vs firewalld

| UFW | firewalld |
|------|-----------|
| Simple interface | Zone-based firewall |
| Easy to configure | More flexible |
| Recommended for small servers | Common in enterprise systems |

UFW was chosen because it is lightweight and sufficient for the project requirements.

### VirtualBox vs UTM

| VirtualBox | UTM |
|-------------|-----|
| Windows, Linux and macOS | Mainly macOS |
| Mature and widely used | Optimized for Apple Silicon |
| Large community | Smaller ecosystem |

VirtualBox was selected because it is cross-platform and officially supported by the project.

---

# Project Design

## Virtual Machine

- Debian
- 4 GB RAM
- 10 GB virtual disk
- 2 CPUs

## Partition Layout

The system uses encrypted storage with LUKS and LVM.

```
Disk
├── /boot
└── LUKS
    └── LVM
        ├── /
        ├── swap
        ├── /srv
        └── /var/log
```

## Security

- SSH running on port **4242**
- Root login disabled
- UFW enabled
- Password expiration policy
- Strong password requirements using PAM
- Sudo logging enabled
- Cron executes a monitoring script every 10 minutes

---

# Instructions

## Requirements

- VirtualBox
- Debian ISO

## SSH

Connect from the host machine:

```bash
ssh <username>@localhost -p 2222
```

## Useful Commands

Start SSH:

```bash
sudo systemctl restart ssh
```

Firewall status:

```bash
sudo ufw status
```

Display partition layout:

```bash
lsblk -f
```

Display LVM information:

```bash
lvdisplay
```

Check password policy:

```bash
chage -l <user>
```

View sudo logs:

```bash
cat /var/log/sudo/sudo.log
```

Stop cron temporarily:

```bash
sudo systemctl stop cron
```

---

# Monitoring Script

Every 10 minutes a Bash script gathers system information and broadcasts it using `wall`.

The script reports:

- Architecture
- Physical and virtual CPUs
- Memory usage
- Disk usage
- CPU load
- Last boot
- LVM status
- Active TCP connections
- Logged users
- IP and MAC addresses
- Number of sudo commands executed

---

# Resources

Official documentation used during the project:

- Debian Documentation — https://www.debian.org/doc/
- OpenSSH Documentation — https://www.openssh.com/manual.html
- UFW Manual — https://manpages.debian.org/ufw
- LVM Documentation — https://sourceware.org/lvm2/
- AppArmor Documentation — https://apparmor.net/
- VirtualBox User Manual — https://www.virtualbox.org/manual/

## AI Usage

ChatGPT was used as an auxiliary learning tool to clarify Linux administration concepts, explain system services, review shell scripting questions and improve the English documentation. All system configuration, testing and validation were performed manually.