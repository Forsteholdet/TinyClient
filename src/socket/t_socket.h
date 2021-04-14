#ifndef TINY_CLIENT_T_SOCKET_H
#define TINY_CLIENT_T_SOCKET_H
#include <unistd.h>
#include "macro/macro_defs.h"

namespace tinyclient{
    class t_socket {
    public:
        virtual TinyString send(TinyString url){

            return "hej";
        };
        virtual void recv(){};
        virtual TinyString response(){return "base response";};

        TinyString content = "";

        virtual ~t_socket() { };

    };


}

#endif //TINY_CLIENT_T_SOCKET_H
