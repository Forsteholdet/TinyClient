#ifndef TINY_CLIENT_ESP32SOCKET_H
#define TINY_CLIENT_ESP32SOCKET_H
#ifdef ESP32_SOCKET

#include "t_socket.h"
#include "WiFiClient.h"

using namespace tinyclient;
class ESP32Socket : public t_socket {
        public:
            IPAddress server_ip;
            int port;

            ESP32Socket(int first, int second, int third, int fourth, int port) {
                server_ip = IPAddress(first, second, third, fourth);
                this->port = port;
            }
            
            bool connect() { 
                Serial.println("\nStarting connection to server...");
                if (!client.connect(server_ip, port)) {
                    Serial.println("Connection failed!");
                    return false;
                }
                
                Serial.println("Connected to server!");
                return true;
            }

            void send(TinyString data){
                client.print(data.toCharArray());
            }
            void println(TinyString data){
                client.println(data.toCharArray());
            }

            TinyString recv() {
                TinyString header = recvHeader();
                TinyString body = recvBody();

                return header + body;
            }

            WiFiClient client;

            TinyString recvHeader() {
                while (client.connected()) {
                    TinyString line = client.readStringUntil('\n');
                    if (line == "\r") {
                        Serial.println("headers received");
                    }
                    return line;
                }

                return "";
            }

            TinyString recvBody() {
                TinyString body = "";
                while (client.available()) {
                    char c = client.read();
                    body += c;
                }

                return body;
            }

            void stop(){
                client.stop();
            }


        private:
        
};
#endif // ESP32_SOCKET
#endif // TINY_CLIENT_ESP32SOCKET_H