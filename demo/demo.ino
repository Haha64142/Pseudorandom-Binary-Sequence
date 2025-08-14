// I set the pins to random digital pins on my board. Change these on yours
uint8_t PRBS_OUTPUT_PIN = LED_BUILTIN; // Output pin for the pseudorandom binary sequence (PRBS)
uint8_t INTERRUPT_PIN = 51; // Pin to be used as an interrupt (see PRBS7 function)

// Input pins for activating the PRBS functions
uint8_t PRBS_7_PIN = 47;
uint8_t PRBS_13_PIN = 43;
uint8_t PRBS_20_PIN = 39;

// Starting values for the PRBS (Passed to the functions)
uint8_t START_7 = 0x01; // For PRBS7
uint16_t START_13 = 0x01; // For PRBS13
uint32_t START_20 = 0x01; // For PRBS20

void setup()
{
  Serial.begin(9600); // For printing to the serial plotter. Remove to increase speed
  pinMode(PRBS_OUTPUT_PIN, OUTPUT);
  pinMode(PRBS_7_PIN, INPUT);
  pinMode(PRBS_13_PIN, INPUT);
  pinMode(PRBS_20_PIN, INPUT);
}

void loop()
{
  if (digitalRead(PRBS_7_PIN) == HIGH)
  {
    PRBS7(START_7); // Can also be called with any non-zero 7-bit value, 1-127 (0x01 - 0x7f): PRBS7(0x2f)
  }
  if (digitalRead(PRBS_13_PIN) == HIGH)
  {
    PRBS13(START_13); // Can also be called with any non-zero 13-bit value, 1-8191 (0x01 - 0x1fff): PRBS13(0x3e6)
  }
  if (digitalRead(PRBS_20_PIN) == HIGH)
  {
    PRBS20(START_20); // Can also be called with any non-zero 20-bit value, 1-1048575 (0x01 - 0xfffff): PRBS20(0x24b3a)
  }
}

void PRBS7(uint8_t start)
{
  uint8_t a = start; // unsigned 8-bit integer
  /*
  Replace the for loop line with this one to remove the interrupt pin:
  for (size_t i = 0; i < 127; ++i)

  The important part is this:
  || digitalRead(INTERRUPT_PIN) == HIGH

  That checks if the interrupt pin is high, then performs a logical OR so that it will exit.
  I'm not sure if a digitalRead and a logical OR will make that much of a performance difference, but it's there if you need it.
  */
  for (size_t i = 0; i < 127 && digitalRead(INTERRUPT_PIN) == LOW; ++i) // Can be interrupted (see above)
  {
    bool newbit = ((a >> 6) ^ (a >> 5)) & 1; // bit 6 XOR bit 5 (0 indexed)(6 and 7 standard index)
    a = ((a << 1) | newbit) & 0x7f;
    digitalWrite(PRBS_OUTPUT_PIN, newbit); // Output the newbit
    Serial.println(newbit); // Prints to the serial plotter. Remove to increase speed
  }
}

void PRBS13(uint16_t start)
{
  uint16_t a = start; // unsigned 16-bit integer
  for (size_t i = 0; i < 8191 && digitalRead(INTERRUPT_PIN) == LOW; ++i) // Can be interrupted (see PRBS7)
  {
    bool newbit = ((a >> 12) ^ (a >> 11) ^ (a >> 1) ^ (a >> 0)) & 1; // bit 12 XOR bit 11 XOR bit 1 XOR bit 0 (0 indexed)(13, 12, 2, and 1 standard index)
    a = ((a << 1) | newbit) & 0x1fff;
    digitalWrite(PRBS_OUTPUT_PIN, newbit); // Output the newbit
    Serial.println(newbit); // Prints to the serial plotter. Remove to increase speed
  }
}

void PRBS20(uint32_t start)
{
  uint32_t a = start; // unsigned 32-bit integer
  for (size_t i = 0; i < 1048575 && digitalRead(INTERRUPT_PIN) == LOW; ++i)  // Can be interruptd (see PRBS7)
  {
    bool newbit = ((a >> 19) ^ (a >> 2)) & 1; // bit 19 XOR bit 2 (0 indexed)(20 and 3 standard index)
    a = ((a << 1) | newbit) & 0xfffff;
    digitalWrite(PRBS_OUTPUT_PIN, newbit); // Output the newbit
    Serial.println(newbit); // Prints to the serial plotter. Remove to increase speed
  }
}