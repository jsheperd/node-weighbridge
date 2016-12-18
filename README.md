# node-weighbridge
Test config for nodejs connected to a weighbridge over serial communication.
The testing hardware is a simple arduino connected to the PC simulating the weighbridge. The communication is defined by the producer of the weighbridge. The bridges can connect directly to a PC over RS232 or multiple bridges can be linked onto the same RS485 serial BUS. Each bridge has got a unique name as a char. The messages can be questions or commands.
Each message has got '\r\n' closing.
##Sample message  "AX:B?\r\n"
###'AX'=source(A)-dest(B)
###':message\r\n'

##Question messages
1. Net: 'N?\r\n'
2. Gross: 'B?\r\n'
3. Tara: 'T?\r\n'

##Commands
1. 'T\r\n': show tara on display
2. 'B\r\n': show gross measure on display
3. 'N\r\n': show net measure on display
...


#Communicate with the 'Bridge'
##There are two test for check how PC can discuss with the bridge
1. tester/test_hw.py -> simlest Python appliction
2. tester/test_hw.js -> simlest nodejs appliction

# Resources
1. http://thinkingonthinking.com/serial-communication-with-nodejs
2. https://www.npmjs.com/package/serialport#ubuntudebian-linux
