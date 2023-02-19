/*PWM_AUDIO by Steve Baudains
  (c) Imperial Light and Magic 2022
  This sketch allows an arduino nano to accept RC inputs
  using PWM to trigger a dfplayer mini with a toggle switch 
  and a three position switch

*/


double channel[2];

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(7, 8); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);


  myDFPlayer.begin(mySoftwareSerial);


  myDFPlayer.volume(27);  //Set volume value. From 0 to 30
 
}

void loop() {
  channel[0] = pulseIn(2, HIGH);
  channel[1] = pulseIn(3, HIGH);
 
  Serial.print(channel[0]);
  Serial.print(" - ");
  Serial.println(channel[1]);
  Serial.print(" - ");
  

  if (channel[0] >= 1800) {

    myDFPlayer.play(random(32, 52));  //Play the first mp3
    Serial.println("Playing random happytrack");
    delay(2500);
  }

if (channel[0] <= 1000) {
   
    myDFPlayer.play(random(25, 31));  //Play the first mp3
    Serial.println("Playing random sad track");
    delay(2000);
  }
  if (channel[1] >= 1700) {
    myDFPlayer.play(5);
    Serial.println("Playing Leia message");
    delay(2500);
  }
  

}
