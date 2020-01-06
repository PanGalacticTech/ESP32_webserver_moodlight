/*********
  ESP32 Wifi Mood Light Controller

  Log on to the Wifi Access point, and control PWM output
  on 3 GPIO pins from the browser.


  Origional project from:
  https://randomnerdtutorials.com

  Declan Heard
  09/08/2019
*********/

// Load Wi-Fi library
#include <WiFi.h>

boolean setAccessPoint = false;    // if true set up as AP

boolean setLocalNetwork = true;     // if true set up as Local Network Station

char wifiType[] = {"Local"};  // char array set to Local or to AP?


// Replace with your network credentials for Local Network
const char* Localssid     = "BT-CPA2TT";  //Wifi Name  - SSID
const char* Localpassword = "xGtTfU3gCd6bEV"; //Router Password - PASSWORD

const char* APssid     = "ESP32-wifi-dev";              //Wifi Name  - SSID
const char* APpassword = "12345678";                  //Router Password - PASSWORD       // Minimum 8 Characters

WiFiUDP udp;    // disabled line to use ESP board on local network
                                   

                                  


// Optional Set Static IP Lines
// Set your Static IP address
IPAddress local_IP(192, 168, 1, 10);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 254);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional



boolean setStaticIP = true; // If true sets static IP address when connecting to Local Network
//if false uses router DNS service.

// if softAP set 
//wiFi.softAPIP - This defaults to |192.168.4.1|

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;   //this line working

//will this work as a char string? doubt it tbh
//char header[] = {" "};  // this line not working yet


// Auxiliar variables to store the current output state
String output25State = "off";            // Red LED
String output26State = "off";            // Green LED
String output27State = "off";            // Blue LED



//PWM Properties
const int freq = 5000;                     // PWM frequency
const int resolution = 8;                  // PWM resolution (bits) 8: 0-255

// using the LED pwm controller assign channels 0-15    16 total avaliable
const int ledREDchannel = 0;
const int ledGREENchannel = 1;
const int ledBLUEchannel = 2;

int redPWM = 254;                               // Red LED Level
int greenPWM = 100;                             // Green LED Level
int bluePWM = 100;                               // Blue LED Level



String R = "255";                                 // Strings to hold PWM values which are printed to the browser when called
String G = "255";
String B = "255";                               // they literally do the thing in the printing to the page.



// Assign output variables to GPIO pins
const int output25 = 25;
const int output26 = 26;
const int output27 = 27;



//--------------------------------------------Setup---------------------------------------
void setup() {

  Serial.begin(115200);

  // configure LED PWM functionalitites
  ledcSetup(ledREDchannel, freq, resolution);
  ledcSetup(ledGREENchannel, freq, resolution);
  ledcSetup(ledBLUEchannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(output25, ledREDchannel);
  ledcAttachPin(output26, ledGREENchannel);
  ledcAttachPin(output27, ledBLUEchannel);


  // This code left here incase outputs to be used as digital outputs
  /*
    // Initialize the output variables as outputs
    pinMode(output25, OUTPUT);
    pinMode(output26, OUTPUT);
    pinMode(output27, OUTPUT);

    // Set outputs to LOW
    digitalWrite(output25, LOW);
    digitalWrite(output26, LOW);
    digitalWrite(output27, LOW);
  */




 if (setAccessPoint == true){

 // UNCOMMENT THIS TO USE A STAND ALONE ACCESS POINT

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  
  // Remove the password parameter, if you want the AP (Access Point) to be open
  // WiFi.softAP(APssid, APpassword);
  WiFi.softAP(APssid);


  IPAddress IP = WiFi.softAPIP();                     //wiFi.softAPIP - This defaults to 192.168.4.1
  Serial.print("AP IP address: ");
  Serial.println(IP);
    /// UNCOMMENT THIS TO USE A STAND ALONE ACCESS POINT
    
 } else if (setLocalNetwork == true){  
 
 if (setStaticIP == true){
// Configures static IP address // COMMENT OUT TO DISABLE FOR STANDARD LOCAL ACCESS POINT
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
 }
  
//UNCOMMENT IN THIS SECTION TO USE WITH LOCAL NETWORK
 // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(Localssid);
  WiFi.begin(Localssid, Localpassword);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.getHostname());  // prints hostname. should print espressif

 } else {

  Serial.println ("nahh its fucked mate wifi connection type not assigned");
 }

  server.begin();   // This line always nessissary


}
//------------------------------------^^^^--------Setup---------------------------------------



//--------------------------------------------Main Loop---------------------------------------

void loop() {

  //------------------------ Client HTTP Requests-----------------------------

  WiFiClient client = server.available();   // Listen for incoming clients
   
  if (client) {                               // If a new client connects,
    //     refresh(client);                          // ADDED LINE FORCE REDIRECT?!?    
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
  
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;                        // add that character to the header String
        //  Serial.print(c); //see what was captured   // ADDED LINE << Lets see wtf goes on here.

        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.

          // that's the end of the client HTTP request, so send a response:






          //--------------------------------------------AP--HTTP Response--------------------
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:

           
              
        
             
            client.println("HTTP/1.1 200 OK");           // this line works try this replacement below
              // redirect(client); 
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //--------------------------------^^^^---- HTTP Requests/Response------------------------------------




            //------------------------------------------------GPIO Control and string parsing----------------------------
            // turns the GPIOs on and off:

            GPIOcontrol();       // Switch case for HTTP requests containing GPIO on/off commands





            //------------------------------------------------String Parsing pwm updates----------------------------

            pwmDataParse();          // Sorts incoming HTTP requests containing PWM updates




            //----------------------------------------------------HTML---------------------------------------------------------------
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");




            //---------------------------------------------------------CSS--------------------------------------------------------------
            // CSS to style the on/off buttons

            callCSS(client);  //  function calls CSS sheet    // Must be passed wifi client. dont know why it works but it does.

           
            //-------- Web Page Heading-----------------------------------------------------------------------
            client.println("<body><h1>ESP32 Mood Light</h1>");

           callHTMLobjects(client); // function calls all HTML page objects 

            //-------------------------------------------------------------Display Buttons-------------------------


            //---All this code now handled by allHTMLobjects function          


            //----------------------------------------------GPIO 25--------------RED          
            //----------------------------------------------GPIO 25--------------RED

            //----------------------------------------------GPIO 26--------------Green
            //----------------------------------------------GPIO 26--------------Green
            
            //----------------------------------------------GPIO 27--------------Blue
            //----------------------------------------------GPIO 27--------------Blue              



            //-------------End of Body/ HTML---------

            client.println("</body></html>");


            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");


  }
}
//----------------------------------------^^^----Main Loop---------------------------------------
