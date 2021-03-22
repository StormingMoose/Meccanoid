
#include "MeccaBrain.h"

const int servochain1 = 13;  // Pin for the servo chain

MeccaBrain chain1(servochain1);

int ServoNum = 0;

double Observed_180_Value =  228;
 
double Observed_0_Value = 18;

double Range_180;

int Degree;                  // becomes the input data

byte POS;

void setup() {
    Serial.begin(9600);
    Range_180 = Observed_180_Value - Observed_0_Value;
    
    for (int j =0; j<=20; j++){       
         chain1.communicate();         //  wake it up and turn it blue           
                 }
             
             }

void loop() {

    Serial.print("Input Degrees to move to ");
    while(Serial.available()==0){
    }
    Degree = int(Serial.parseInt());
    Serial.println(Degree);
    
    POS  = Degree*Range_180/180 + Observed_0_Value;
    
    // Serial.println(POS);
    chain1.setServoPosition(ServoNum,POS);
    chain1.communicate();
    
    }
