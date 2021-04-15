

#ifndef TINY_CLIENT_PACKAGE_H
#define TINY_CLIENT_PACKAGE_H

#include "macro/macro_defs.h"

class Package{

    public:
    
    
    Package(TinyString _header, TinyString _body){
        this->header = _header;
        this->body = _body;
    }

    TinyString getHeader(){
        return this->header;
    }

    TinyString getBody(){
        return this->body;
    }

    private:
    TinyString header;
    TinyString body;
};

#endif //TINY_CLIENT_PACKAGE_H