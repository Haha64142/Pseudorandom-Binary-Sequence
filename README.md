# Pseudorandom Binary Sequence (PRBS) implementation on an arduino

## files:
- demo:
  - Contains a sample program with 3 different buttons for PRBS7, PRBS13, and PRBS20.
  - Also contains an interrupt button to stop the output of the PRBS function. (Each time you restart a PRBS function, it resets back to the starting value)
  - Outputs to a pin and to the serial console/plotter on the arduino IDE
  - Contains a bunch of comments for explanation
  
- bare_bones
  - Contains the three main functions PRBS7, PRBS13, and PRBS20
  - Outputs to a pin, defined by a global variable
  - Has a short sample program in the setup function
  - Only has the bare minimum to work, so it should be the fastest
