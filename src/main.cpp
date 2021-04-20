#include <bourne/json.hpp>

#if defined(ESP32)

#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include "socket/TinySocket.h"

const char* ssid = "NOKIA-CE21"; //Enter SSID
const char* password = "R4f6U4pEeS"; //Enter Password


void setup(){
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


    int port = 5000;
    TinySocket client(192,168,87,119, port);

    //client.setCACert(test_root_ca); // SSL
    //client.setCertificate(test_client_key); // for client verification
    //client.setPrivateKey(test_client_cert);	// for client verification
    Serial.println("");
    Serial.println("WiFi connected");
    
    //Print LAN IP.  
    Serial.print("IP address set: ");
    Serial.println(WiFi.localIP());
    
    
    ///////////////////////
    ///// Socket //////////
    ///////////////////////
    Serial.println("socket: " + client.server_ip.toString());
    Serial.println("port: " + client.port);
    client.connect();
        
    // Make a HTTP request:
    client.println("GET /test HTTP/1.1");
    client.println("Host: http://" + client.server_ip.toString() + ":" + client.port);
    client.println("accept: application/json");
    client.println("");
    
    TinyString header = client.recvHeader();
    TinyString body = client.recvBody();

    Serial.print("header: ");
    Serial.println(header.toCharArray());
    Serial.print("body: ");
    Serial.println(body.toCharArray());

    client.stop();
  
}
void loop(){}


#else
int main(){
    return 1;
}
#endif