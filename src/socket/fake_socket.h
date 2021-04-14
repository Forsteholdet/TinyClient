#ifndef TINY_CLIENT_FAKE_SOCKET_H
#define TINY_CLIENT_FAKE_SOCKET_H
#include "t_socket.h"
using namespace tinyclient;

class fake_socket : public t_socket{
public:
    TinyString send(TinyString str) {
        content += str;
        return "fake";
    }

    TinyString content = "";

    TinyString response() {
        return "response";
    }

    ~fake_socket() { }
};


#endif //TINY_CLIENT_FAKE_SOCKET_H
