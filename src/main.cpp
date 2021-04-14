#include <bourne/json.hpp>

#if defined(ESP32)
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "NOKIA-CE21"; //Enter SSID
const char* password = "R4f6U4pEeS"; //Enter Password


void setup(){
    const IPAddress ipserver(192,168,87,133);
    const int port = 5000;
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
  
  Serial.println("\nStarting connection to server...");
  if (!client.connect(ipserver, port))
    Serial.println("Connection failed!");
  else {
    Serial.println("Connected to server!");
    
    // Make a HTTP request:
    client.println("POST /test HTTP/1.1");
    client.println("Host: http://" + ipserver.toString() + (String)port);
    client.println("accept: application/json");
    client.println();
    
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("headers received");
        break;
      }
    }
    // if there are incoming bytes available
    // from the server, read them and print them:
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }

    client.stop();
  }



}
void loop(){}


#else
int main(){
    return 1;
}
#endif