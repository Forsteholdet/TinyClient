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

    int find(NativeString str){
        auto ret = _str.find(str.toCharArray());
        if(ret == std::string::npos)
            return -1;
        else
            return ret;
    }

    friend bool operator== (const NativeString &lhs, const NativeString &rhs){
        return lhs._str == rhs._str;
    }

    NativeString& operator+=(const NativeString& rhs){
        this->_str += rhs._str;
        return *this;
    }

private:
    std::string _str;

};

#endif
