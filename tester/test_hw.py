#!/usr/bin/python

import serial, time
ser = serial.Serial('/dev/ttyUSB0')  # open serial port


def comm(msg):
    print("msg: %s" % msg)
    ser.write("AX:%s\r\n" % msg )
    resp = ser.readline()
    print resp

print(ser.name)         # check which port was really used

msgs = ['N?', 'B?', 'T?', 'NU', 'TA', 'BR', 'NT', 'TR', 'kamu']


# test he device
for msg in msgs:
    time.sleep(1)
    comm(msg)


ser.close()
