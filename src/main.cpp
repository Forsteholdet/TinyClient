#include <iostream>

#include <sys/socket.h>
#include "http_request.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    tinyclient::t_socket socket;
    http_request client(&socket);

    std::string response = socket.send("bla");

    std::cout << "json response: " << response;

    return 0;
}
