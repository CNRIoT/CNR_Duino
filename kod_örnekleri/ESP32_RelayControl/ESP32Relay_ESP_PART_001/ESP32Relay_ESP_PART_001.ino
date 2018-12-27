
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

HardwareSerial Serial2(2);
// Choose two free pins
//#define SERIAL1_RXPIN 16
//#define SERIAL1_TXPIN 17




// Replace with your network credentials
const char* ssid     = "Cemoka";
const char* password = "CEMOKANOYAN";

WiFiServer server(80);

const int led1 =  23;      // the number of the LED pin
const int led2 =  2;      // the number of the LED pin

// Client variables 
char linebuf[80];
int charcount=0;

void setup() {
  // initialize the LEDs pins as an output:
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
  
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  Serial2.begin(115200);
  //Serial1.begin(9600, SERIAL_8N1, SERIAL1_RXPIN, SERIAL1_TXPIN);
  while(!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
    Serial2.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  // attempt to connect to Wifi network:
  while(WiFi.status() != WL_CONNECTED) {
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial2.println("WiFi connected");
  Serial2.println("IP address: ");
  //Serial.write("kakiru\r\n");

  //ArduinoOTA.setHostname("monEsp"); // give an name to our module
  
  server.begin();
  ArduinoOTA.begin(); // OTA initialization
}

void loop() {
   ArduinoOTA.handle();
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client");
    memset(linebuf,0,sizeof(linebuf));
    charcount=0;
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        //read char by char HTTP request
        linebuf[charcount]=c;
        if (charcount<sizeof(linebuf)-1) charcount++;
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println();
          client.println("<!DOCTYPE HTML><html><head>");
          client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>");
          client.println("<h1>CNRDuino ESP32 - Web Server</h1>");
          client.println("<p>ROLE #1 <a href=\"on1\"><button>ON</button></a>&nbsp;<a href=\"off1\"><button>OFF</button></a></p>");
          client.println("<p>ROLE #2 <a href=\"on2\"><button>ON</button></a>&nbsp;<a href=\"off2\"><button>OFF</button></a></p>");
          client.println("<p>ROLE #3 <a href=\"on3\"><button>ON</button></a>&nbsp;<a href=\"off3\"><button>OFF</button></a></p>");
          client.println("<p>ROLE #4 <a href=\"on4\"><button>ON</button></a>&nbsp;<a href=\"off4\"><button>OFF</button></a></p>"); 
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
          if (strstr(linebuf,"GET /on1") > 0){
            Serial2.println("1");
           // Serial2.println("1");
            Serial2.write('1');
            //digitalWrite(17, HIGH);
          }
          else if (strstr(linebuf,"GET /off1") > 0){
            Serial2.println("2");
             Serial2.write('2');
              // Serial2.println("0");
           // digitalWrite(17, LOW);
          }
          else if (strstr(linebuf,"GET /on2") > 0){
            Serial2.println("3");
             Serial2.write('3');
            digitalWrite(led2, HIGH);
          }
          else if (strstr(linebuf,"GET /off2") > 0){
            Serial2.println("4");
             Serial2.write('4');
            digitalWrite(led2, LOW);
          }
           else if (strstr(linebuf,"GET /on3") > 0){
            Serial2.println("5");
             Serial2.write('5');
          //  digitalWrite(led2, LOW);
          }
           else if (strstr(linebuf,"GET /off3") > 0){
            Serial2.println("6");
             Serial2.write('6');
          //  digitalWrite(led2, LOW);
          }
           else if (strstr(linebuf,"GET /on4") > 0){
            Serial2.println("7");
             Serial2.write('7');
         //   digitalWrite(led2, LOW);
          }
           else if (strstr(linebuf,"GET /off4") > 0){
            Serial2.println("8");
             Serial2.write('8');
           // digitalWrite(led2, LOW);
          }
          // you're starting a new line
          currentLineIsBlank = true;
          memset(linebuf,0,sizeof(linebuf));
          charcount=0;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);

    // close the connection:
    client.stop();
   // Serial.println("client disconnected");
  }
}
