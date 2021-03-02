//
// Created by anders on 3/2/21.
//

#include <bourne/json.hpp>

#ifndef TINY_CLIENT_RESPONSE_H
#define TINY_CLIENT_RESPONSE_H

namespace tinyclient{


class response {
public:
    response(int code, const std::string& body){
        this->code = code;
        this->body = bourne::json { "key1", "Value"};
    }

    bourne::json body;

    int code;
    std::string message;


};

const static int ok = 200;

}


#endif //TINY_CLIENT_RESPONSE_H
