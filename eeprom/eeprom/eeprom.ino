#include<stdio.h>
#include<stdlib.h>

char x = 'x';

void setup() {
  EEARL = 0;
  EECR = 0;
  EECR |= (1 << EEPM1);

  while(1)
  {
    if (!(EECR & (1 << EEPE)))
      break;
  }

  while(1)
  {
    if (!(SELFPRGEN & (1 << SPMCSR)))
      break;
  }

  EEDR = x;
  //delay(2);
  EECR = EECR | (1 << EEMPE);// & (0 << EEPE);
  EECR |= (1 << EEPE);
  Serial.begin(9600);  
}

void loop() {    
  while(1)
  {
    if (!(EECR & (1 << EEPE)))
      break;
  }
  
  EEARL = 0;
  EECR |= (1 << EERE);
  Serial.write(EEDR);
  Serial.println();
}
