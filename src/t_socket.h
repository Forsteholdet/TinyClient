#ifndef TINY_CLIENT_T_SOCKET_H
#define TINY_CLIENT_T_SOCKET_H
#include <unistd.h>
#include <string>


namespace tinyclient{
    class t_socket {
    public:
        virtual std::string send(std::string url){

            return "hej";
        };
        virtual void recv(){};
        virtual std::string response(){return "base response";};

        std::string content;
    };

}

#endif //TINY_CLIENT_T_SOCKET_H
