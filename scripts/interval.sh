#!/bin/bash

RTC_DEVICE=/dev/rtc0

dev_path=/sys`udevadm info -q path -n $RTC_DEVICE`

SE=`cat $dev_path/since_epoch`
INTERVAL=900

wakeup_at=$(cat << EOF | bc -q 
a=$SE
b=a % $INTERVAL
c=a-b
print c + $INTERVAL
EOF
)


echo $wakeup_at
