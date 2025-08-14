int PRBS_OUTPUT_PIN = 1;

void setup()
{
  pinMode(PRBS_OUTPUT_PIN, OUTPUT);
  PRBS7(0x01); // Sample stuff
}

void PRBS7(uint8_t start)
{
  uint8_t a = start;
  for (size_t i = 0; i < 127; ++i)
  {
    bool newbit = ((a >> 6) ^ (a >> 5)) & 1;
    a = ((a << 1) | newbit) & 0x7f;
    digitalWrite(PRBS_OUTPUT_PIN, newbit);
  }
}

void PRBS13(uint16_t start)
{
  uint16_t a = start;
  for (size_t i = 0; i < 8191; ++i)
  {
    bool newbit = ((a >> 12) ^ (a >> 11) ^ (a >> 1) ^ (a >> 0)) & 1;
    a = ((a << 1) | newbit) & 0x1fff;
    digitalWrite(PRBS_OUTPUT_PIN, newbit);
  }
}

void PRBS20(uint32_t start)
{
  uint32_t a = start;
  for (size_t i = 0; i < 1048575; ++i) 
  {
    bool newbit = ((a >> 19) ^ (a >> 2)) & 1;
    a = ((a << 1) | newbit) & 0xfffff;
    digitalWrite(PRBS_OUTPUT_PIN, newbit);
  }
}