#ifndef TINY_CLIENT_ESP32SOCKET_H
#define TINY_CLIENT_ESP32SOCKET_H
#include "t_socket.h"

using namespace tinyclient;
class ESP32Socket : public t_socket {
        public:
            ESP32Socket(int first, int second, int third, int fourth, int port) {

            }
            
            bool connect() { return true; };
        private:
    };
#endif // TINY_CLIENT_ESP32SOCKET_H