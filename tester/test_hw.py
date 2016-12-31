#!/usr/bin/python

import serial, time
ser = serial.Serial('/dev/ttyUSB0')  # open serial port


def comm(msg):
    print("msg: %s" % msg)
    ser.write("XA/%s\r\n" % msg )
    resp = ser.readline()
    print resp

print(ser.name)         # check which port was really used

msgs = ['kamu', 'N?', 'B?', 'T?']


# test he device
for msg in msgs:
    time.sleep(1)
    comm(msg)


ser.close()
