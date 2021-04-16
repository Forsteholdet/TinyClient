#include <bourne/json.hpp>

#if defined(ESP32)
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include "socket/ESP32Socket.h"

const char* ssid = "NOKIA-CE21"; //Enter SSID
const char* password = "R4f6U4pEeS"; //Enter Password


void setup(){
    int port = 5000;
    const IPAddress ipserver(192,168,87,119);
    WiFiClient client;

    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    delay(100);
    
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);


  // attempt to connect to Wifi network:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    // wait 1 second for re-trying
    delay(1000);
  }

  Serial.print("Connected to ");
  Serial.println(ssid);

  //client.setCACert(test_root_ca); // SSL
  //client.setCertificate(test_client_key); // for client verification
  //client.setPrivateKey(test_client_cert);	// for client verification

  Serial.println("");
  Serial.println("WiFi connected");
  
  //Print LAN IP.  
  Serial.print("IP address set: ");
  Serial.println(WiFi.localIP());
  
  ESP32Socket socket(192,168,87,119,port);
  Serial.println("socket: " + socket.server_ip.toString());
  Serial.println("port: " + socket.port);
  socket.connect();
    
  // Make a HTTP request:
  socket.println("GET /test HTTP/1.1");
  socket.println("Host: http://" + ipserver.toString() + ":" + socket.port);

  socket.println("accept: application/json");
  socket.println("");
  
  TinyString header = socket.recvHeader();
  // if there are incoming bytes available
  // from the server, read them and print them:
  TinyString body = socket.recvBody();

  Serial.print("header: ");
  Serial.println(header.toCharArray());
  Serial.print("body: ");
  Serial.println(body.toCharArray());

  socket.close();
  client.stop();
}
void loop(){}


#else
int main(){
    return 1;
}
#endif