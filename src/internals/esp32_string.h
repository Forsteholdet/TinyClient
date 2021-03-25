#ifndef TINY_CLIENT_ESP32STRING_H
#define TINY_CLIENT_ESP32STRING_H

#endif //TINY_CLIENT_ESP32STRING_H
#if defined(ESP32)
#include <Arduino.h>

class ESP32String{
public:

    String str;

    ESP32String(const char* string) {

        str = String(string);
    }

    //void strcpy(TCstring *dest, const TCstring *src){}

    int length(){
        return str.Length();
    }

//    bool empty(){
//        return str.Empty();
//    }

    ESP32String substr(int pos, int count){
        auto stringToReturn = str.substring(pos, count);
        return ESP32String(stringToReturn.c_str());
    }

    friend bool operator== (const ESP32String &lhs, const ESP32String &rhs){
        return lhs.str == rhs.str;
    }
};

#endif
