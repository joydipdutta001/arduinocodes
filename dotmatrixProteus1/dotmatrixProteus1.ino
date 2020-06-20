#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10
#define WAIT_TIME 1000
#define sensor    A0
int  Vin;          
float  Temperature; 
int     TF;

MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);
void setup(void)
{
  P.begin();
  pinMode(sensor,INPUT);
}

void loop(void)
{
  
  P.print("ASIF");
  delay(WAIT_TIME);

 
}
