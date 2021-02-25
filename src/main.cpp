#include <iostream>

#include <sys/socket.h>
#include "http_client.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    tinyclient::t_socket socket;
    http_client client(&socket);

    std::string response = socket.send("bla");

    std::cout << "json response: " << response;

    return 0;
}
