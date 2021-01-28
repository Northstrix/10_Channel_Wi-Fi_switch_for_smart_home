// 10_Channel_Wi-Fi_switch_for_smart_home
// © Copyright Maxim Bortnikov 2021
// For more information and for the schematics of this device visit: https://github.com/Northstrix/10_Channel_Wi-Fi_switch_for_smart_home
#include <ESP8266WiFi.h> 
const char* ssid     = "Mobile Hotspot 1290";  // Your SSID (Network's name)
const char* password = "seasidehills1234"; // Password from your network
/*
int ch4 = 15; // pin D8
int ch5 = 16; // pin D0
int ch6 = 5;  // pin D1
int ch7 = 4;  // pin D2
int ch8 = 0;  // pin D3
int ch9 = 2;  // pin D4*/
// Display
int clk=16; // clk pin
int data=5; // di pin
// Counter and latches
#define cdat 14 // cdat pin
#define res 12 // reset pin
#define ref 13 // refresh (latch) pin
bool a[2][4]={
  {1,0,1,1},
  {1,0,1,0}  
};
  int c1 = 0; // Setting all variables to 0 by default
  int c2 = 0;
  int c3 = 0;
  int c4 = 0;
  int c5 = 0;
  int c6 = 0;
  int c7 = 0;
  int c8 = 0;
  int c9 = 0;
  int c10 = 0;
  int x,b,z,d,e,f;
WiFiServer server(80);
void clr(){
  digitalWrite(data,LOW);
for(int i=0;i<40;i++){
  digitalWrite(clk,HIGH);
  delayMicroseconds(1);
  digitalWrite(clk,LOW);
  delayMicroseconds(1);
}
}
void out(int n){
    for(int j=0;j<4;j++){
    if(a[n][j]==1){
    digitalWrite(data,HIGH);}
    else{
      digitalWrite(data,LOW);}
      digitalWrite(clk,HIGH);
  delayMicroseconds(1);
  digitalWrite(clk,LOW);
  delayMicroseconds(1);
  }
}
void cbpe (int n){
  digitalWrite(res, HIGH); //set 0 to all output
  delayMicroseconds(1);
  digitalWrite(res, LOW); // allow the counter to count
  delayMicroseconds(1);
  
  for (int i = 0; i<n; i++){ // cdat output
    digitalWrite(cdat, HIGH);
    delayMicroseconds(1);
    digitalWrite(cdat, LOW);
    delayMicroseconds(1);    
  }
  
  digitalWrite(ref, HIGH); // refresh
  delayMicroseconds(1);
  digitalWrite(ref, LOW);
}
void setup(){
  clr();
  Serial.begin(115200); // Baudrate
  pinMode(clk,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
  pinMode(0,OUTPUT);
  digitalWrite(0,LOW);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  pinMode(15,OUTPUT);
  digitalWrite(15,LOW);
  pinMode(cdat, OUTPUT);
  pinMode(res, OUTPUT);
  pinMode(ref, OUTPUT);
  digitalWrite(res, HIGH);
  digitalWrite(cdat, LOW);
  digitalWrite(ref, LOW);
  Serial.print("Connecting to the Newtork"); // This all will be displayed in the Serial Monitor
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected"); 
  server.begin(); // Starting the server
  Serial.println("Server started");
  Serial.print("IP Address of network: ");
  Serial.println(WiFi.localIP());
  Serial.println("/");
  out(c1);
  out(c2);
  out(c3);
  out(c4);
  out(c5);
  out(c6);
  out(c7);
  out(c8);
  out(c9);
  out(c10);  

}

 

void loop(){
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())  
  {
    delay(1);
  } 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  if(request.indexOf("/ch1=ON") != -1)

  {
    digitalWrite(4, HIGH); // Turn ch1 ON
    c1 = 1;
  }
  if(request.indexOf("/ch1=OFF") != -1)
  {
    digitalWrite(4, LOW); // Turn ch1 OFF
    c1 = 0;
  }

  if(request.indexOf("/ch2=ON") != -1)

  {
    digitalWrite(0, HIGH); // Turn ch2 ON
    c2 = 1;
  }
  if(request.indexOf("/ch2=OFF") != -1)
  {
    digitalWrite(0, LOW); // Turn ch2 OFF
    c2 = 0;
  }

  if(request.indexOf("/ch3=ON") != -1)

  {
    digitalWrite(2, HIGH);
    c3 = 1;
  }
  if(request.indexOf("/ch3=OFF") != -1)
  {
    digitalWrite(2, LOW);
    c3 = 0;
  }

  if(request.indexOf("/ch4=ON") != -1)

  {
    digitalWrite(15, HIGH);
    c4 = 1;
  }
  if(request.indexOf("/ch4=OFF") != -1)
  {
    digitalWrite(15, LOW);
    c4 = 0;
  }
  
  if(request.indexOf("/ch5=ON") != -1)

  {
    x=1;
    c5 = 1;
  }
  if(request.indexOf("/ch5=OFF") != -1)
  {
    x=0;
    c5 = 0;
  }
  
  if(request.indexOf("/ch6=ON") != -1)

  {
    b=2;
    c6 = 1;
  }
  if(request.indexOf("/ch6=OFF") != -1)
  {
    b=0;
    c6 = 0;
  }

  if(request.indexOf("/ch7=ON") != -1)

  {
    z=4;
    c7 = 1;
  }
  if(request.indexOf("/ch7=OFF") != -1)
  {
    z=0;
    c7 = 0;
  }

  if(request.indexOf("/ch8=ON") != -1)

  {
    d=8;
    c8 = 1;
  }
  if(request.indexOf("/ch8=OFF") != -1)
  {
    d=0;
    c8 = 0;
  }

  if(request.indexOf("/ch9=ON") != -1)

  {
    e=16;
    c9 = 1;
  }
  if(request.indexOf("/ch9=OFF") != -1)
  {
    e=0;
    c9 = 0;
  }

  if(request.indexOf("/ch10=ON") != -1)

  {
    f=32;
    c10 = 1;
  }
  if(request.indexOf("/ch10=OFF") != -1)
  {
    f=0;
    c10 = 0;
  }
  clr();
  delayMicroseconds(1);
  out(c1);
  out(c2);
  out(c3);
  out(c4);
  out(c5);
  out(c6);
  out(c7);
  out(c8);
  out(c9);
  out(c10);
  cbpe(x+b+z+d+e+f);  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html"); // All below is a web page code written in HTML
  client.println("");
  client.println("<!DOCTYPE html>\n"
"<html>\n"
" <head>\n"
" <meta name='viewport' content='width=device-width, initial-scale=1.0'/>\n"
" <meta charset='utf-8'>\n"
"    <style>\n"
"  * {\n"
"  margin: 0;\n"
"  padding: 0;\n"
"}\n"
"html,\n"
"body {\n"
"  //      background-image: linear-gradient(-120deg, #26E289 0, #1a5fa2 100%, red 200%);\n"
"  background: \n"
"  linear-gradient(135deg, black 25%, transparent 25%) -50px 0,\n"
"  linear-gradient(225deg, black 25%, transparent 25%) -50px 0,\n"
"  linear-gradient(315deg, black 25%, transparent 25%),\n"
"  linear-gradient(45deg, black 25%, transparent 25%);\t\n"
"  background-size: 2em 2em;\n"
"  background-color: #D0D0D0;\n"
"  font-family: Segoe UI,Frutiger,Frutiger Linotype,Dejavu Sans,Helvetica Neue,Arial,sans-serif; \n"
"  font-weight: 400;\n"
"  box-sizing: border-box;\n"
"  height: 100%;\n"
"  width: 100%;\n"
"}\n"
"}\n"
".noselect {\n"
"  -webkit-touch-callout: none;\n"
"    -webkit-user-select: none;\n"
"     -khtml-user-select: none;\n"
"       -moz-user-select: none;\n"
"        -ms-user-select: none;\n"
"            user-select: none;\n"
"\t\t-webkit-tap-highlight-color: transparent;\n"
"}\n"
"\n"
".button {\n"
"\twidth: 70%;\n"
"\theight: 50px;\n"
"  text-decoration: none;\n"
"\tcursor: pointer;\n"
"\tbackground-color: #0072E3;\n"
"\tborder: none;\n"
"  color: #EEE;\n"
"\tborder-radius: 30px;\n"
"  background-image: linear-gradient(-120deg, #0072E3 0, #1a5fa2 100%);\n"
"\tbox-shadow: 0 0 200px rgba(255,255,255,0.0);\n"
"\ttransition: 1s;\n"
"\tdisplay: flex;\n"
"\talign-items: center;\n"
"\tjustify-content: center;\n"
"  margin: 5px;\n"
"}\n"
".button2{\n"
"background-image: linear-gradient(-120deg, #FA253C 0, #F4253C 100%); \n"
"}\n"
"\n"
"button:after {\n"
"\tposition: absolute;\n"
"\tcontent: '';\n"
"\twidth: 25px;\n"
"\theight: 25px;\n"
"\tborder-radius: 100%;\n"
"\tbackground: transparent;\n"
"\tbox-shadow: 0 0 80px rgba(255,255,255,1);\n"
"}\n"
"\n"
"button:hover {\n"
"\tbox-shadow: 0 0 100px rgba(255,255,255,1);\n"
"}\n"
"\n"
"button:hover:after {\n"
"\tanimation: animate 3s infinite linear;\n"
"}\n"
"\n"
"button:focus {\n"
"\toutline: none;\n"
"}\n"
"\n"
"@keyframes animate {\n"
"\t0% { transform: translateX(60px)}\n"
"\t50% {transform: translateX(-60px)}\n"
"\t100% {transform: translateX(60px)}\n"
"}\n"
".buttons {\n"
"  display: flex;\n"
"  flex-direction: row;\n"
"  flex-wrap: wrap;\n"
"  justify-content: center;\n"
"  text-align: center;\n"
"  width: 100%;\n"
"  height: 100%;\n"
"  margin: 0 auto;\n"
"}\n"
".container {\n"
"  display: inline-block;\n"
"  align-items: center;\n"
"  display: flex;\n"
"  flex-direction: column;\n"
"  justify-content: top;\n"
"  text-align: center;\n"
"  background-image: linear-gradient(-135deg, #26E289 0, #4093e0 100%);\n"
"  padding:  40px 0px; \n"
"  width: 300px;\n"
"  margin-top: 10vh;\n"
"  margin-bottom: 10vh;\n"
"  margin-left: auto;\n"
"  margin-right: auto;\n"
"  //border-top: solid 1px rgba(255,255,255,.5);\n"
"  border-radius: 10px;\n"
"  box-shadow: 0px 2px 7px rgba(0,0,0,0.2);\n"
"  overflow: hidden;\n"
"}\n"
"h1 {\n"
"  text-align: center;\n"
"  color: #EEE;\n"
"  letter-spacing: 0.05em;\n"
"  margin: 0 0 0.4em;\n"
"  font-size: 1em;\n"
"}\n"
"p {\n"
"  text-align: left;\n"
"  color: #EEE;\n"
"  letter-spacing: 0.05em;\n"
"  font-size: 0.8em;\n"
"  margin: 0 0 2em;\n"
"}    \n"
"</style>\n"
" <title>ESP8266-based 10 channel Wi-Fi switch</title>\n"
"</head>\n"
"<body>\n"
"  <div class=\"buttons\">\n"
"  <div class=\"container\">\n"
"      <h1>10 channel Wi-Fi switch</h1>\n"
"      <p>Developed by Maxim Bortnikov</p>\n"
"\n"
"      <p>Channel 1</p>\n"
"      <a href=\"ch1=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch1=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 2</p>\n"
"      <a href=\"ch2=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch2=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 3</p>\n"
"      <a href=\"ch3=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch3=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 4</p>\n"
"      <a href=\"ch4=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch4=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 5</p>\n"
"      <a href=\"ch5=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch5=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 6</p>\n"
"      <a href=\"ch6=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch6=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 7</p>\n"
"      <a href=\"ch7=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch7=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 8</p>\n"
"      <a href=\"ch8=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch8=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 9</p>\n"
"      <a href=\"ch9=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch9=OFF\" class=\"button button2\">OFF</a>\n"
"            </br>\n"
"      <p>Channel 10</p>\n"
"      <a href=\"ch10=ON\" class=\"button\">ON</a>\n"
"      <a href=\"ch10=OFF\" class=\"button button2\">OFF</a>\n"
"  </div>\n"
"</div>\n"
"</body>\n"
"</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
