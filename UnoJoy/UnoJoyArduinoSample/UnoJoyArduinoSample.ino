
/* ==================================================================================================================================================
         Project: HUGO Delire / Arduino
         Author: tmator@gmail.com 
         Site: http://bricerouanet.net
===================================================================================================================================================== */
#include "UnoJoy.h"

//DTMF module / Arduino PIN
const int STQ = 6;        
const int Q4 = 5;     
const int Q3 = 4;  
const int Q2 = 3;
const int Q1 = 2;


void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  pinMode(STQ, INPUT);
  pinMode(Q4, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q1, INPUT);
}

dataForController_t getControllerData(void){

  int number=0;
  if(digitalRead(STQ)==HIGH){       //DTMF
   
    if(digitalRead(Q1)==HIGH){      

      number+=1;
    }
    if(digitalRead(Q2)==HIGH){     

      number+=2;
    }
    if(digitalRead(Q3)==HIGH){      

      number+=4;
    }
    if(digitalRead(Q4)==HIGH){      

      number+=8;
    }

  }

 dataForController_t controllerData = getBlankDataForController();

  controllerData.triangleOn = LOW;
  controllerData.circleOn = LOW;
  controllerData.squareOn = LOW;
  controllerData.crossOn = LOW;
  controllerData.dpadUpOn = LOW;
  controllerData.dpadDownOn = LOW;
  controllerData.dpadLeftOn = LOW;
  controllerData.dpadRightOn = LOW;
  controllerData.startOn = LOW;

  if (number==1)
  {
    controllerData.triangleOn = HIGH;
  }
  else if (number==2)
  {
    controllerData.dpadUpOn = HIGH;
  }
  else if (number==3)
  {
    controllerData.circleOn = HIGH;
  }
  else if (number==4)
  {
    controllerData.dpadLeftOn = HIGH;
  }
  else if (number==5)
  {
    controllerData.startOn = HIGH;
  }
  else if (number==6)
  {
    controllerData.dpadRightOn = HIGH;
  }
  else if (number==7)
  {
    controllerData.squareOn = HIGH;
  }
  else if (number==8)
  {
    controllerData.dpadDownOn = HIGH;
  }
  else if (number==9)
  {
    controllerData.crossOn = HIGH;
  }


  // And return the data!
  return controllerData;
}
