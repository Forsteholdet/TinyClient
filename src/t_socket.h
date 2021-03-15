#ifndef TINY_CLIENT_T_SOCKET_H
#define TINY_CLIENT_T_SOCKET_H
#include <unistd.h>
#include <Arduino.h>


namespace tinyclient{
    class t_socket {
    public:
        virtual String send(String url){

            return "hej";
        };
        virtual void recv(){};
        virtual String response(){return "base response";};

        String content;
    };

}

#endif //TINY_CLIENT_T_SOCKET_H
