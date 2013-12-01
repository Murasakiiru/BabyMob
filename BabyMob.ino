#include <SPI.h> 
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>
#include <Servo.h>

Servo monServo;
int servoPin = 5;
SdFat sd;
SFEMP3Shield MP3player;

void setup() {

  monServo.attach(servoPin);
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
  MP3player.playTrack(1);
}

void loop() {
  monServo.write(90);
}
