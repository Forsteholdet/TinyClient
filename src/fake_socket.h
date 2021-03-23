#ifndef TINY_CLIENT_FAKE_SOCKET_H
#define TINY_CLIENT_FAKE_SOCKET_H
#include <Arduino.h>

#include "t_socket.h"
using namespace tinyclient;

class fake_socket : public t_socket{
public:
    String send(String str) {
        content += str;
        return "fake";
    }

    String content;

    String response() {
        return "response";
    }
};


#endif //TINY_CLIENT_FAKE_SOCKET_H
