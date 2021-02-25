#ifndef TINY_CLIENT_T_SOCKET_H
#define TINY_CLIENT_T_SOCKET_H
#include <string>
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <netdb.h>
#include <sstream>


namespace tinyclient{
    class t_socket {
    public:
        virtual std::string send(std::string url){
            int sock;
            struct sockaddr_in client;

            struct hostent * host = gethostbyname("127.0.0.1");

            if ( (host == NULL) || (host->h_addr == NULL) ) {
                std::cout << "Error retrieving DNS information." << std::endl;
                exit(1);
            }

            bzero(&client, sizeof(client));
            client.sin_family = AF_INET;
            client.sin_port = htons( 5000 );
            memcpy(&client.sin_addr, host->h_addr, host->h_length);

            sock = socket(AF_INET, SOCK_STREAM, 0);

            if (sock < 0) {
                std::cout << "Error creating socket." << std::endl;
                exit(1);
            }

            if ( connect(sock, (struct sockaddr *)&client, sizeof(client)) < 0 ) {
                close(sock);
                std::cout << "Could not connect" << std::endl;
                exit(1);
            }

            std::stringstream ss;
            ss << "GET / HTTP/1.1\r\n"
               << "Host: 127.0.0.1\r\n"
               << "Accept: application/json\r\n"
               << "\r\n\r\n";
            std::string request = ss.str();

            if (::send(sock, request.c_str(), request.length(), 0) != (int)request.length()) {
                std::cout << "Error sending request." << std::endl;
                exit(1);
            }

            char cur;
            while ( read(sock, &cur, 1) > 0 ) {
                std::cout << cur;
            }
            std::cout << std::endl;

            return "hej";
        };
        virtual void recv(){};
        virtual std::string response(){return "base response";};

        std::string content;
    };

}

#endif //TINY_CLIENT_T_SOCKET_H
