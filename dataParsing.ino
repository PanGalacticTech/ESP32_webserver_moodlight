/*
   Routeins for data parsing and switch cases


*/


//------------------------------------------------GPIO Control and string parsing----------------------------
// turns the GPIOs on and off:

void GPIOcontrol() {

  if (header.indexOf("GET /25/off") >= 0) {
    Serial.println("GPIO 25 off");
    output25State = "off";
    ledcWrite(ledREDchannel, 0);
  } else if (header.indexOf("GET /25/on") >= 0) {
    Serial.println("GPIO 25 on");
    output25State = "on";
    ledcWrite(ledREDchannel, redPWM);
  }

  else if (header.indexOf("GET /26/off") >= 0) {
    Serial.println("GPIO 26 off");
    output26State = "off";
    ledcWrite(ledGREENchannel, 0);
  } else if (header.indexOf("GET /26/on") >= 0) {
    Serial.println("GPIO 26 on");
    output26State = "on";
    ledcWrite(ledGREENchannel, greenPWM);
  }

  else if (header.indexOf("GET /27/off") >= 0) {
    Serial.println("GPIO 27 off");
    output27State = "off";
    ledcWrite(ledBLUEchannel, 0);
  } else if (header.indexOf("GET /27/on") >= 0) {
    Serial.println("GPIO 27 on");
    output27State = "on";
    ledcWrite(ledBLUEchannel, bluePWM);
  }

}
//------------------------------------------^^^-----GPIO Control-------------------------






//------------------------------------------------String Parsing pwm updates----------------------------


//--------------------- RED LEVEL SORTING--------------------
void pwmDataParse() {                      ////int channelPWM, String     // channelPWM = pass redPWM/greenPWM or bluePWM

  if (header.indexOf("GET /?redPWM=") >= 0) {                      // If the header contains the command for the red channel

    int stringLength =  header.length() + 1;                      // work out the length of char array needed to hold the String
    // object header.

    char copy[stringLength];                                    /// this is long....like 535 characters long wtf man.
    // it works but damn there has to be a better way
    header.toCharArray(copy, stringLength);                     // copy the String - header. to char copy
    // This data is now indexed and can be sorted.


    int j = 0;                                               // another variable to be used along with i to control indexes
    char u[4];                                              // char array to hold our new brightness value - later use R variable?

    for (int i = 13; i < 16; i++) {                       // Example of copy[] = GET /?redPWM=100 max is 16, start of int is 13
      u[j] = copy[i];
      j++;                                                  // increment j along with for loop
    }


    redPWM = atoi( u );                                 // put char array into redPWM value as int.

    Serial.println(redPWM);

    R = redPWM;                                          // save redPWM value into string object R

    for (int i = 0; i < sizeof(copy); i++) {               // Resets copy buffer maybe unneeded

      copy[i] = (char)0;
    }

    if (output25State == "on") {                           // set the new LED brightness if the LED is already on
      ledcWrite(ledREDchannel, redPWM);
    } else {
      ledcWrite(ledREDchannel, 0);
    }
  } //--------------------- RED LEVEL SORTING--------------------



  //--------------------- Green LEVEL SORTING--------------------

  if (header.indexOf("GET /?greenPWM=") >= 0) {

    int stringLength =  header.length() + 1;

    char copy[stringLength];                                    /// this is long....like 535 characters long wtf man.
    // it works but damn there has to be a better way
    header.toCharArray(copy, stringLength);                     //


    int j = 0;                                               // another variable to be used along with i to control indexes
    char u[4];                                              // char array to hold our new brightness value - later use R variable
    // and change to char array
    for (int i = 15; i < 18; i++) {                       // Example of copy[] = GET /?redPWM=100 max is 16, start of int is 14
      u[j] = copy[i];
      j++;                                                  // increment j along with for loop
    }


    greenPWM = atoi( u );                                 // put char array into redPWM value as int.

    Serial.println(greenPWM);

    G = greenPWM;                                          // save redPWM value into string object R

    for (int i = 0; i < sizeof(copy); i++) {               // Resets copy buffer maybe unneeded

      copy[i] = (char)0;
    }

    if (output26State == "on") {
      ledcWrite(ledGREENchannel, greenPWM);
    } else {
      ledcWrite(ledGREENchannel, 0);
    }
  } //--------------------- Green LEVEL SORTING--------------------




  //--------------------- Blue LEVEL SORTING--------------------
  if (header.indexOf("GET /?bluePWM=") >= 0) {

    int stringLength =  header.length() + 1;

    char copy[stringLength];                                    /// this is long....like 535 characters long wtf man.
    // it works but damn there has to be a better way
    header.toCharArray(copy, stringLength);                     //


    int j = 0;                                               // another variable to be used along with i to control indexes
    char u[4];                                              // char array to hold our new brightness value - later use R variable
    // and change to char array
    for (int i = 14; i < 17; i++) {                       // Example of copy[] = GET /?redPWM=100 max is 16, start of int is 14
      u[j] = copy[i];
      j++;                                                  // increment j along with for loop
    }


    bluePWM = atoi( u );                                 // put char array into redPWM value as int.

    Serial.println(bluePWM);

    B = bluePWM;                                          // save redPWM value into string object R

    for (int i = 0; i < sizeof(copy); i++) {               // Resets copy buffer maybe unneeded

      copy[i] = (char)0;
    }

    if (output27State == "on") {
      ledcWrite(ledBLUEchannel, bluePWM);
    } else {
      ledcWrite(ledBLUEchannel, 0);
    }
  } //--------------------- Green LEVEL SORTING--------------------


}
