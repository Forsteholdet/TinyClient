//
// Created by kaare on 3/19/21.
//

#ifndef TINY_CLIENT_TCSTRING_H
#define TINY_CLIENT_TCSTRING_H

#endif //TINY_CLIENT_TCSTRING_H

#if defined(__linux) || defined(_WIN32)

#include "string"

class NativeString{
public:



    NativeString(const char* string) {

        _str = std::string(string);
    }

    int length(){
        return _str.length();
    }

    NativeString substr(int pos, int count) {
        auto stringToReturn = _str.substr(pos, count);
        return NativeString(stringToReturn.c_str());
    }

    bool empty(){
        return _str.empty();
    }

    const char* toCharArray() {
        return _str.c_str();
    }

    friend bool operator== (const NativeString &lhs, const NativeString &rhs){
        return lhs._str == rhs._str;
    }

private:
    std::string _str;

};

#endif
