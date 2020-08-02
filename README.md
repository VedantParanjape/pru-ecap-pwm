# pru-ecap-pwm

Using PRU's eCap module to generate PWM

# Compile

```bash
pru-gcc main0.c -o pwm -I./include/ -I./include/am335x/ -mmcu=am335x.pru0
```

# Usage

```
cp pwm /lib/firmware/am335x-pru0-fw
config-pin p9.42 pru_ecap
echo start > /sys/class/remoteproc/remoteproc0/state
```
* Connect a LED to pin 42 on P9 header to see LED brightness change
