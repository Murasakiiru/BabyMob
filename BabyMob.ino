    #include <Fat16util.h>
    #include <NewSPI.h>
    #include "MusicPlayer.h"
     
    //Création of the MusicPlayer object
    MusicPlayer myplayer;
     
    void setup() {
      //Serial monitor opening ...
      Serial.begin(9600);
      //Initialization of the MusicPlayer
      myplayer.begin();
      //Disable the Joystick, to enable the Pins
      myplayer.keyDisable();
      //Enable analog Pins
      myplayer.analogControlEnable();
      //Enable digital Pins
      myplayer.digitalControlEnable();
      
      //Attach a function on the HIGH level of the 4th Pin
      myplayer.attachDigitOperation(4, nextTrack, HIGH);
      //Attach a function on the 5th analog Pin
      myplayer.attachAnalogOperation(A5, adjustVolume);
    }
     
    void loop() {
      //Select the player mode (MODE_NORMAL | MODE_SHUFFLE | MODE_REPEAT_LIST)
      myplayer.setPlayMode(MODE_SHUFFLE);
      //Browse the SDcard and create a list with all songs found
      myplayer.creatPlaylist();
      //Play the list
      myplayer.playList();
    }
    
    void adjustVolume() {
      //'Map' the vol variable on the potentiometer
      byte vol = map(analogRead(A5), 0, 1023, 0, 139);
      //Ajuste the volume
      myplayer.setVolume(vol);
    }
     
    void nextTrack() {
      //Play next song when button pushed
      myplayer.opNextSong();
      //50ms delay
      delay(50);
    }


