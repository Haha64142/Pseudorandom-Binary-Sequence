int PRBS_OUTPUT_PIN = 13;

volatile uint8_t *prbsOutPort;
uint8_t prbsBitMask;

void setup()
{
  setupPRBSOutPin(PRBS_OUTPUT_PIN);
}

void loop()
{
  PRBS20(0x01); // Sample PRBS20 use
}

void setupPRBSOutPin(uint8_t pin) {
  uint8_t port = digitalPinToPort(pin);
  if (port == NOT_A_PIN) {
    Serial.println("Error: Invalid PRBS_OUTPUT_PIN");
    while (1);
  }

  prbsOutPort = portOutputRegister(port);
  prbsBitMask = digitalPinToBitMask(pin);

  pinMode(pin, OUTPUT);
}

void PRBS7(uint8_t start)
{
  uint8_t a = start;
  for (size_t i = 0; i < 127; ++i)
  {
    bool newbit = ((a >> 6) ^ (a >> 5)) & 1;
    a = ((a << 1) | newbit) & 0x7f;
    
    if (newbit)
    {
      *prbsOutPort |= prbsBitMask;
    }
    else
    {
      *prbsOutPort &= ~prbsBitMask;
    }

  }
}

void PRBS13(uint16_t start)
{
  uint16_t a = start;
  for (size_t i = 0; i < 8191; ++i)
  {
    bool newbit = ((a >> 12) ^ (a >> 11) ^ (a >> 1) ^ (a >> 0)) & 1;
    a = ((a << 1) | newbit) & 0x1fff;

    if (newbit)
    {
      *prbsOutPort |= prbsBitMask;
    }
    else
    {
      *prbsOutPort &= ~prbsBitMask;
    }
  }
}

void PRBS20(uint32_t start)
{
  uint32_t a = start;
  for (size_t i = 0; i < 1048575; ++i) 
  {
    bool newbit = ((a >> 19) ^ (a >> 2)) & 1;
    a = ((a << 1) | newbit) & 0xfffff;
    
    if (newbit)
    {
      *prbsOutPort |= prbsBitMask;
    }
    else
    {
      *prbsOutPort &= ~prbsBitMask;
    }
  }
}