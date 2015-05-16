#!/bin/bash

RTC_DEVICE=/dev/rtc0

CLOCKOUT="CLOCKOUT"
nIRQ2="nIRQ2"

dev_path=/sys`udevadm info -q path -n $RTC_DEVICE`
TIMER_OUT_PIN=$nIRQ2

echo "Found device: $dev_path"

#Disable Countdown
echo 0 > $dev_path/timer/TE

#Set timer registers
echo 0 > $dev_path/status/TIM
echo 1 > $dev_path/timer/TM
echo 0 > $dev_path/timer/TRPT
echo 2 > $dev_path/timer/TFS
echo 5 > $dev_path/timer/countdown

if [ "$TIMER_OUT_PIN" == "$CLOCKOUT" ]
then
	echo "Using CLOCK OUT"
	echo 27 > $dev_path/sqw/SQFS
	echo 1 > $dev_path/sqw/SQWE

elif [ "$TIMER_OUT_PIN" == "$nIRQ2" ]
then

	echo "Using nIRQ2"
	echo 1 > $dev_path/int/TIE
	echo 5 > $dev_path/control2/OUT2S

else
	echo "Pin output selection failed"
	exit 3
fi

#Enable Countdown
echo 1 > $dev_path/timer/TE

cat /proc/driver/rtc

echo
echo

while test 0 -eq `cat $dev_path/status/TIM`;
do
	date
	sleep 1
	cat $dev_path/timer/countdown
done
