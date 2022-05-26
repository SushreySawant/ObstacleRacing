#include <NIBOburger.h>                                                           /* Sushrey Sawant AIMS 2021-22 NIbo Burger Prog1 Wall detection, Final code with IR sensor values adjusted for detection and indication*/
 
void setup() {
  NIBOburger.begin();
}

void loop() {
  NIBOburger.checkVoltage();
  int speed = 0;
  int st = 0;
  char sw = NIBOburger.getKeyChar();
  unsigned int r = SensorFRR.get();     /* Fetching extreme right IR sensor data*/
  unsigned int l = SensorFLL.get();    /* Fetching extreme left IR sensor data*/
  unsigned int rr = SensorFR.get();    /* Fetching center right IR sensor data*/
  unsigned int ll = SensorFL.get();    /* Fetching center left IR sensor data*/                                              

  if (sw!=0) {                          /* Monitoring switch pressing for starting motor*/ 
    switch (sw) {
      
      case 'a':speed= 2000;
     
        break;    /* Monitoring switch release for SW1 */ 


      
      case 'B': speed = 0; break;       /* Monitoring switch press for SW2 */ 
      
    }  
    Engine.setPWM(speed, speed);
  
  }


  if (l>25 || ll>75) {  /* Monitoring obstacles from IR sensor data values */
    NIBOburger.setLed(LED4, r>25);            /* Indicating obstacles from IR sensor data values via LEDs*/
    NIBOburger.setLed(LED1, l>25);
    NIBOburger.setLed(LED2, ll>75);
    NIBOburger.setLed(LED3, rr>50);
    Engine.setPWM(700, 0);
     delay(200);
    Engine.setPWM(2000, 2000);
  }

if (r>25 || rr>50) {  /* Monitoring obstacles from IR sensor data values */
    NIBOburger.setLed(LED4, r>25);            /* Indicating obstacles from IR sensor data values via LEDs*/
    NIBOburger.setLed(LED1, l>25);
    NIBOburger.setLed(LED2, ll>75);
    NIBOburger.setLed(LED3, rr>50);
     delay(100);
    Engine.setPWM(0, 700);
 delay(200);
    Engine.setPWM(2000, 2000);
  }

if (ll>75 && rr>50) { 
  Engine.setPWM(-800, -800);
  delay(1200);
  Engine.setPWM(2000, 2000);
}
  
  
    NIBOburger.setLed(LED4, r>25);            /* Indicating obstacles from IR sensor data values via LEDs*/
    NIBOburger.setLed(LED1, l>25);
    NIBOburger.setLed(LED2, ll>75);
    NIBOburger.setLed(LED3, rr>50);
 

    


 

    
/*
  if (l>25) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);
    NIBOburger.setLed(LED1, l>25);
  }
  

  if (l>25 || ll>15) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);
    NIBOburger.setLed(LED3, rr>15);
    NIBOburger.setLed(LED4, r>25);
  }
*/



  
  delay(10);
}












/*Working code with obstacle indicating LEDs



#include <NIBOburger.h>
 
void setup() {
  NIBOburger.begin();
}

void loop() {
  NIBOburger.checkVoltage();
  int speed = 0;
  char sw = NIBOburger.getKeyChar();
  unsigned int r = SensorFRR.get();
  unsigned int l = SensorFLL.get();
  unsigned int rr = SensorFR.get();
  unsigned int ll = SensorFL.get();

  
  if (sw!=0) {  
    switch (sw) {
      case 'a': speed = 800; break;
      case 'B': speed = 0; break;
      
    }  
    Engine.setPWM(speed, speed);
  }



  if (r>25 || l>25) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);

  }

  if (rr>50 || ll>75) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);

  }
    NIBOburger.setLed(LED4, r>25);
    NIBOburger.setLed(LED1, l>25);
    NIBOburger.setLed(LED2, ll>75);
    NIBOburger.setLed(LED3, rr>50);
/*
  if (l>25) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);
    NIBOburger.setLed(LED1, l>25);
  }
  

  if (l>25 || ll>15) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);
    NIBOburger.setLed(LED3, rr>15);
    NIBOburger.setLed(LED4, r>25);
  }
*/



  
  /*delay(10);
}


*/








































/*Working code without LED
#include <NIBOburger.h>
 
void setup() {
  NIBOburger.begin();
}

void loop() {
  NIBOburger.checkVoltage();
  int speed = 0;
  char c = NIBOburger.getKeyChar();
  unsigned int r = SensorFRR.get();
  unsigned int l = SensorFLL.get();
  if (c!=0) {  
    switch (c) {
      case 'a': speed = 800; break;
      case 'B': speed = 0; break;
      case 'c': speed = -800; break;
    }  
    Engine.setPWM(speed, speed);
  }



  if (r>25) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);
  }

  if (l>25) {  
    speed = 0 ;
    Engine.setPWM(speed, speed);
  }




  
  delay(10);
}






*/




















/*
#include <NIBOburger.h>


void setup() 

{
  NIBOburger.begin();  // put your setup code here, to run once:

}

void loop() 
{


  NIBOburger.checkVoltage();
  int speed = 0;
  char c = 0;
  unsigned int irl = 0;
  unsigned int irr = 0;
  c = NIBOburger.getKeyChar();
  irl = SensorFL.get();
  irr = SensorFR.get();


if (c=='A')
{
 
          
                              
                  
                              delay(500);
                                                 if (irl > 25)

                              {
                                speed = 000;
                                
                              }
                             


                                delay(500);
                                                 if (irr > 25)

                              {
                                speed = 000;
                                
                              }
                             

                                                         

  speed = 500;
  Engine.setPWM(speed, speed);


delay(100);
                             
Engine.setPWM(speed, speed);

                             

}



  
  delay(10);
}

*/
















  

  



