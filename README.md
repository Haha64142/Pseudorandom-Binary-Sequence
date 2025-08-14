# Pseudorandom Binary Sequence (PRBS) implementation on an arduino

## Files
- demo:
  - Contains a sample program with 3 different buttons for PRBS7, PRBS13, and PRBS20
  - Also contains an interrupt button to stop the output of the PRBS function (Each time you restart a PRBS function, it resets back to the starting value)
  - Outputs to a pin and to the serial console/plotter on the arduino IDE
  - Contains a bunch of comments for explanation
  - Uses fast write for writing to the output pin
  - Uses fast read for reading the interrupt pin
  
- bare_bones
  - Please go through the demo file before using this one
  - Contains the three main functions PRBS7, PRBS13, and PRBS20
  - Outputs to a pin, defined by a global variable
  - Has a short sample program in the setup function
  - Only has the bare minimum to work, and uses fast write, so it should be the absolute fastest
  - I've tested PRBS13, and got ~400,000 bits/sec, or ~0.4 Mbps

> **Note**: The fast write only works on arduino AVR board, such as the Mega, UNO, and Micro. If you want to use non-AVR boards, you need to switch back to digitalWrite

## Speed
### digitalWrite
| PRBS |	Bits |	Duration | Bits/sec | µs/bit |	Hertz |
| :---: | :---: | :---: | :---: | :---: | :---: |
| PRBS7 |	127 |	1,273  µs |	99,800	| 10.03	| 100 kHz |
| PRBS13	| 8,191 |	63,369  µs |	129,300	| 7.74 |	129 kHz |
| PRBS20	| 1,048,575 |	16,747,624  µs |	62,600	| 15.96 |	63 kHz |

### Fast Write
| PRBS	| Bits | Duration | Bits/sec | µs/bit | Hertz | Speed increase vs digitalWrite |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| PRBS7	| 127 |	445 µs |	285,000	| 3.5 |	285 kHz | 2.87× |
| PRBS13	| 8,191 |	20,350 µs |	402,500	| 2.48 |	403 kHz | 3.12× |
| PRBS20	| 1,048,575 |	12,296,984 µs |	85,200	| 11.7	| 85.5 kHz | 1.36× |
