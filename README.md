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
