#!/bin/bash
#
# Firewall: Simple
#
/sbin/iptables -F
/sbin/iptables -X
/sbin/iptables -Z
/sbin/iptables -P INPUT DROP
/sbin/iptables -P OUTPUT ACCEPT
/sbin/iptables -A INPUT -j ACCEPT -i lo
/sbin/iptables -A OUTPUT -j ACCEPT -o lo
/sbin/iptables -A INPUT -j ACCEPT -m conntrack --ctstate ESTABLISHED,RELATED
/sbin/iptables -A INPUT -j DROP

