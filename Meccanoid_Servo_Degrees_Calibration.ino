
#include "MeccaBrain.h"               // ensure the functions inside are availabe via the chain1. command

const int servochain1 = 13;           // Pin for the servo chain

MeccaBrain chain1(servochain1);       // Set up the library function references

int ServoNum = 0;                     // Only using one servo

double Observed_180_Value =  228;     // servo display data when visual 180 degrees is confirmed
 
double Observed_0_Value = 18;         // servo display data when visual 0 degrees is confirmed

double Range_180;                     // calculated number that holds the servo positions in 180 degrees

double Degree;                        // calculated from the servo POSition

byte POS;                             // value sent from the servo


void setup() {         // run once it opens the serial window communication frequency and calculates the Range to be used for this servo
    Serial.begin(9600);
    Range_180 = Observed_180_Value - Observed_0_Value;
             }

void loop() {                                   // keep doing this over and over
  
    chain1.setServotoLIM(ServoNum);             // let the servo be turned by hand
    POS  = chain1.getServoPosition(ServoNum);   // get the value from the servo
    chain1.communicate();                       // send the above two commands to the servo chain
    if (POS >= 1) {    // avoid the 3 zeros
      Serial.print("Observation value ");
      Serial.print(POS);                        // display the servo data enter data above for 0 and 180 degrees
      Serial.println(" enter into program after viewing alignment");           
      Degree = POS - Observed_0_Value;          // adjust for the opening play
      Degree = Degree/Range_180*180;            // calibrate
      Serial.print("Angle is ");
      Serial.print(Degree);                     // show the result
      Serial.println(" degrees");
      delay(1000);                              // slow down the screen scrolling
    }
    }
