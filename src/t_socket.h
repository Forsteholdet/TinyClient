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


namespace tinyclient{
    class t_socket {
    public:
        virtual std::string send(std::string url){
            int sock = 0, valread;
            struct sockaddr_in serv_addr;
            std::string hello = "GET http://randomuser.me/api/ HTTP/1.1\\r\\n\\r\\n";
            char buffer[4096] = {0};
            if ((sock = ::socket(AF_INET, SOCK_STREAM, 0)) < 0)
            {
                printf("\n Socket creation error \n");
                std::exit(-1);
            }

            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(443);

            struct hostent *hp;
            auto host = "randomuser.me";
            if((hp = gethostbyname(host)) == NULL){
                herror("gethostbyname");
                exit(1);
            }
            bcopy(hp->h_addr, &serv_addr.sin_addr, hp->h_length);


            if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            {
                printf("\nConnection Failed \n");
                std::exit(-1);
            }
            ::send(sock , &hello , hello.length() , 0 );
            printf("Hello message sent\n");
            valread = ::read( sock , buffer, 4096);
            std::string response = buffer;
            return response;
        };
        virtual void recv(){};
        virtual std::string response(){return "base response";};
    };

}

#endif //TINY_CLIENT_T_SOCKET_H
