//
// Created by kaare on 3/19/21.
//

#ifndef TINY_CLIENT_TCSTRING_H
#define TINY_CLIENT_TCSTRING_H

#endif //TINY_CLIENT_TCSTRING_H

#if defined(__linux) || defined(_WIN32)

#include "string"

class TCstringLinux{
public:

    std::string str;

    TCstringLinux(const char* string) {

        str = std::string(string);
    }

    int length(){
        return str.length();
    }

    TCstringLinux substr(int pos, int count) {
        auto stringToReturn = str.substr(pos, count);
        return TCstringLinux(stringToReturn.c_str());
    }

    bool empty(){
        return str.empty();
    }

    friend bool operator== (const TCstringLinux &lhs,const TCstringLinux &rhs){
        return lhs.str == rhs.str;
    }

};

#endif


#if defined(ESP32)

#include <Arduino.h>

class TCstringEsp32{
public:

    String str;

    TCstringEsp32(const char* string) {

        str = String(string);
    }

    //void strcpy(TCstring *dest, const TCstring *src){}

    int length(){
        return str.Length();
    }

//    bool empty(){
//        return str.Empty();
//    }

    TCstringEsp32 substr(int pos, int count){
        auto stringToReturn = str.substring(pos, count);
        return TCstringEsp32(stringToReturn.c_str());
    }

    friend bool operator== (const TCstringEsp32 &lhs,const TCstringEsp32 &rhs){
        return lhs.str == rhs.str;
    }
};

#endif

