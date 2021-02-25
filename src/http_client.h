#ifndef TINY_CLIENT_HTTP_CLIENT_H
#define TINY_CLIENT_HTTP_CLIENT_H

#include <string>
#include "fake_socket.h"
#include "bourne/json.hpp"

using namespace std;

class http_client {

public:
    explicit http_client(tinyclient::t_socket* socket_p) {
        socket = socket_p;
    }

    std::string get(string url){
        string request("GET");

        socket->send(request);

        return socket->response();
    };

private:
    tinyclient::t_socket *socket;
};




#endif //TINY_CLIENT_HTTP_CLIENT_H
