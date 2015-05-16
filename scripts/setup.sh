#!/bin/bash

RTC_DEVICE=/dev/rtc0


dev_path=/sys`udevadm info -q path -n $RTC_DEVICE`

echo "Found device: $dev_path"

rtcwake -s 5 --mode no
echo 0 > $dev_path/status/ALM
echo 1 > $dev_path/timer/RPT
echo 1 > $dev_path/int/AIE
echo 0 > $dev_path/int/IM
echo 3 > $dev_path/control2/OUT1S

cat /proc/driver/rtc

echo
echo

while test 0 -eq `cat $dev_path/status/ALM`;
do
	date
	sleep 1
done
