#include <Servo.h>
#include <NewPing.h> 
int trig=A0;
int echo=A1;
int trig1= A2;
int echo1=A3;
NewPing sonar(trig,echo);
NewPing sonar1(trig1,echo1);
Servo abc;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
abc.attach(9);
abc.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(sonar1.ping_cm()<15)
  {
    Serial.println(" Object detected");
    if(radar());
    {
      Serial.println("car Confirmed");
      while(sonar1.ping_cm()<20)
      {
        delay (30);
      }
      Serial.println("Car Removed");
      
    }
  
   
  }
  
}
boolean radar()
{
  int flag =0, flag1=0;
  for(int i =90;i<150;i=i+2)
  {
    abc.write(i);
    int d= sonar.ping_cm();
    if(d>50&&d<70)
    {
      flag=-1;
    }
    else
    flag=1;
    delay(30);
  }
  for(int i=90;i>30;i=i-2)
  {
     abc.write(i);
    int d= sonar.ping_cm();
    if(d>50&&d<70)
    {
      flag1=-1;
    }
    else
    flag1=1;
    delay(30);
    
  }
  if (flag==-1&&flag1==-1)
  {
    return true;
  }
  else
  return false;
}

