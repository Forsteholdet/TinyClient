#ifndef TINY_CLIENT_ESP32STRING_H
#define TINY_CLIENT_ESP32STRING_H


#if defined(ESP32)
#include <Arduino.h>
#include "bourne/json.hpp"
class ESP32String{
public:



    ESP32String(const char* str) {

        _str = String(str);
    }

    ESP32String(String basicString){
        _str = basicString;
    }

    ESP32String(bourne::json jsonObj){
        _str = jsonObj.dump();
    }

    int length() const{
        return _str.length();
    }

    bool empty(){
        return _str == "";
    }

    const char* toCharArray() const{
        return _str.c_str();
    }

    int find(const ESP32String& str) const{
        return _str.indexOf(str.toCharArray());
    }

    int find(const char* c) const{
        return _str.indexOf(c);
    }

    bool ends_with(ESP32String const &b) {
        auto len = b.length();
        auto pos = _str.length() - len;
        auto a_arr = _str.c_str();
        auto b_arr = b._str.c_str();
        if (pos < 0)
            return false;
        auto pos_a = &a_arr[pos];
        auto pos_b = &b_arr[0];
        while (*pos_a)
            if (*pos_a++ != *pos_b++)
                return false;
        return true;
    }

    ESP32String substr(int pos, int count) const{
        auto stringToReturn = _str.substring(pos, count);
        return ESP32String(stringToReturn.c_str());
    }

    friend bool operator== (const ESP32String &lhs, const ESP32String &rhs){
        return lhs._str == rhs._str;
    }

    friend ESP32String operator+ (const ESP32String &lhs, const ESP32String &rhs){
        return lhs._str + rhs._str;
    }


    ESP32String& operator+=(const ESP32String& rhs){
        this->_str += rhs._str;
        return *this;
    }

private:
    String _str;
};

#endif
#endif //TINY_CLIENT_ESP32STRING_H