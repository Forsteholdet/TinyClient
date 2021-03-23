#ifndef TINY_CLIENT_FAKE_SOCKET_H
#define TINY_CLIENT_FAKE_SOCKET_H
#include <string>

#include "t_socket.h"
using namespace tinyclient;

class fake_socket : public t_socket{
public:
    std::string send(std::string str) {
        content += str;
        return "fake";
    }

    std::string content;

    std::string response() {
        return "response";
    }
};


#endif //TINY_CLIENT_FAKE_SOCKET_H
