#include <Servo.h>
//defining Servos
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

//Assigning LDRs
int ldrtopl = 0; //top left LDR green
int ldrtopr = 1; //top right LDR yellow
 void setup () 
 {
  servohori.attach(10);
  servohori.write(90);
  delay(500);
 }

void loop()
{
  servoh = servohori.read();
  //capturing analog values of each LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  // calculating average
  int avgleft = topl; //average of left LDRs
  int avgright = topr; //average of right LDRs

  if (avgleft < avgright)
  {
    servohori.write(servoh -1);
    if (servoh > servohLimitLow)
    {
    servoh = servohLimitLow;
    }
    delay(30);
  }
  else if (avgright < avgleft)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
    delay(30);
  }
  else 
  {
    servohori.write(servoh);
  }
  delay(50);
}
