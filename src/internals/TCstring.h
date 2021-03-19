//
// Created by kaare on 3/19/21.
//

#ifndef TINY_CLIENT_TCSTRING_H
#define TINY_CLIENT_TCSTRING_H

#endif //TINY_CLIENT_TCSTRING_H

#if define(__linux)
#include "string.h"
#endif


class TCstring(){
public:
    void strcpy(Tcstring dest, TCstring src){}

    int strlen(const Tcstring *str){}

    TCstring substr(int pos, int count){}
}

class TCstringLinux(): public TCstring{
public:

    void strcpy(Tcstring *dest, const Tcstring *src){
        std::strcpy(dest, src);

    }

    std::size_t strlen(const Tcstring *str){
        return std:strlen(str);
    }

    Tcstring substr(int pos, int count) {
        return std::substr(pos, count)
    }


}