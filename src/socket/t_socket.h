#ifndef TINY_CLIENT_T_SOCKET_H
#define TINY_CLIENT_T_SOCKET_H
#include <unistd.h>
#include "macro/macro_defs.h"
#include "response/response.h"

namespace tinyclient{
    class t_socket {
    public:
        virtual void send(TinyString url){ };
        virtual TinyString recv(){};
        virtual TinyString response(){return "base response";};

        TinyString content = "";

        virtual ~t_socket() { };

    };


}

#endif //TINY_CLIENT_T_SOCKET_H
