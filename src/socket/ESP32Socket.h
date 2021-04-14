#ifndef TINY_CLIENT_ESP32SOCKET_H
#define TINY_CLIENT_ESP32SOCKET_H
#include "t_socket.h"
using namespace tinyclient;
{
    class ESP32Socket : public t_socket {
        public:
            bool connect() { return true; };
        private:
    };
} // namespace tinyclinet
#endif // TINY_CLIENT_ESP32SOCKET_H