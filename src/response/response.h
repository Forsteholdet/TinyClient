//
// Created by anders on 3/2/21.
//



#ifndef TINY_CLIENT_RESPONSE_H
#define TINY_CLIENT_RESPONSE_H
#include <bourne/json.hpp>
#include "macro/macro_defs.h"


const static int ok = 200;

class Response {
public:
    Response(int code, const TinyString& body){
        this->code = code;
        this->body = bourne::json { "key1", "Value"};
    }

    bourne::json body;

    int code;
    TinyString message = "";

};



#endif //TINY_CLIENT_RESPONSE_H
