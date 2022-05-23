#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

ESP8266WebServer server(80);    // Create a webserver object that listens for HTTP request on port 80

 
const char* ssid = "MySpectrumWiFi40-2G";//type your ssid
const char* password = "brightdoll483";//type your password
 
//int ledPin = 2; // GPIO2 of ESP8266
//WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
 
  //pinMode(ledPin, OUTPUT);
  //digitalWrite(ledPin, LOW);
   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  wifiMulti.addAP("MySpectrumWiFi40-2G", "brightdoll483");   // add Wi-Fi networks you want to connect to
  

  //WiFi.mode(WIFI_STA); // for addressing disconnection issue
   
  //WiFi.begin(ssid, password);
  
  //WiFi.setAutoReconnect(true); // for addressing disconnection issue
  //WiFi.setSleepMode(WIFI_NONE_SLEEP); // for addressing disconnection issue

  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(250);
    Serial.print('.');
  }
   
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }

  Serial.println("");
  Serial.println("WiFi connected");

  if (MDNS.begin("esp8266")) {              // Start the mDNS responder for esp8266.local
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  
   
  // Start the server
  server.begin();
  Serial.println("Server started");
  //digitalWrite(ledPin, HIGH);
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
    
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
  //int value = LOW;
  int heart = 0;
  int cry = 0;
  int haha = 0;
  int fuck = 0;
  
  int awkward = 0;
  int relax = 0;
  int sleepy = 0;
  int jiong = 0;
  int cao = 0;
  int laugh = 0;
  if (request.indexOf("/heart") != -1) {
    Serial.println("heart");
    heart = 1;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 0;
  } 
  else if (request.indexOf("/cry") != -1) {
    Serial.println("cry");
    heart = 0;
    cry = 1;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 0;
  } 
  else if (request.indexOf("/haha") != -1) {
    Serial.println("haha");
    heart = 0;
    cry = 0;
    haha = 1;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 0;
  } 
  else if (request.indexOf("/fuck") != -1) {
    Serial.println("fuck");
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 1;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 0;
  } 
  
  else if (request.indexOf("/awkward") != -1) {
    Serial.println("awkward");
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 1;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 0;
  } 
  else if (request.indexOf("/relax") != -1) {
    Serial.println("relax");
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 1;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 0;
  } 
  else if (request.indexOf("/sleepy") != -1) {
    Serial.println("sleepy");
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 1;
    jiong = 0;
    cao = 0;
    laugh = 0;
  } 
  else if (request.indexOf("/jiong") != -1) {
    Serial.println("jiong");
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 1;
    cao = 0;
    laugh = 0;
  } 
  else if (request.indexOf("/cao") != -1) {
    Serial.println("cao");
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 1;
    laugh = 0;
  } 
  else if (request.indexOf("/laugh") != -1) {
    Serial.println("laugh");
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 1;
  } 
  
  else{
    Serial.println();
    heart = 0;
    cry = 0;
    haha = 0;
    fuck = 0;
    awkward = 0;
    relax = 0;
    sleepy = 0;
    jiong = 0;
    cao = 0;
    laugh = 0;
  }

 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
   
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   
  client.print("You message: ");
   
  if(heart == 1) {
    client.print("heart");  
  } else if(cry == 1) {
    client.print("cry");  
  } else if (haha == 1) {
    client.print("haha");  
  } else if (fuck == 1) {
    client.print("fuck");  
  } else if(awkward == 1) {
    client.print("awkward");  
  } else if (relax == 1) {
    client.print("relax");  
  } else if (sleepy == 1) {
    client.print("sleepy");  
  }else if(jiong == 1) {
    client.print("jiong");  
  } else if (cao == 1) {
    client.print("cao");  
  } else if (laugh == 1) {
    client.print("laugh");  
  } else {
    client.print("");
  }
  
  client.println("<br><br>");
  client.println("<a href=\"/heart\">heart</a><br>");
  client.println("<a href=\"/cry\">cry</a><br>");
  client.println("<a href=\"/haha\">haha</a><br>");
  client.println("<a href=\"/fuck\">fuck</a><br>");

  client.println("<a href=\"/awkward\">awkward</a><br>");
  client.println("<a href=\"/relax\">relax</a><br>");
  client.println("<a href=\"/sleepy\">sleepy</a><br>");
  client.println("<a href=\"/jiong\">jiong</a><br>");
  client.println("<a href=\"/cao\">cao</a><br>");
  client.println("<a href=\"/laugh\">laugh</a><br>");
  
  client.println("<a href=\"/\">[back]</a><br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
