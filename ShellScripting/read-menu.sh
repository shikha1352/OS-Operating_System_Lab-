#!/usr/bin/env bash
# read-menu: a menu driven system information program
clear
cat << DONE
Please Select:

    1. Display System Information
    2. Display Disk Space
    3. Display Home Space Utilization
    0. Quit

DONE
echo 
read -p 'Enter selection [0-3]: ' sel

case $sel in
	0) echo "Program terminated.";;
	1) echo "Hostname: $HOSTNAME"; uptime;;
	2) df -h;;
	3)
		if [ "$UID" = 0 ]; then
			echo "Home Space Utilization (All Users)"
			du -sh /home/*
		else
			echo "Home Space Utilization ($USER)"
			du -sh "$HOME"
		fi
	;;
	*)
		echo "Invalid entry." >&2
		exit 1
esac