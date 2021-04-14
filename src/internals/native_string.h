#ifndef TINY_CLIENT_TCSTRING_H
#define TINY_CLIENT_TCSTRING_H



#if defined(__linux) || defined(_WIN32)

#include "string"
#include "bourne/json.hpp"

class NativeString{
public:


    NativeString(const char* str) {

        _str = std::string(str);
    }

    NativeString(std::string basicString) {
        _str = std::move(basicString);

    }

    NativeString(bourne::json jsonObj){
        _str = jsonObj.dump();
    }

    

    int length() const{
        return _str.length();
    }

    NativeString substr(int pos, int count) const{
        auto stringToReturn = _str.substr(pos, count);
        return NativeString(stringToReturn.c_str());
    }

    bool empty() const{
        return _str.empty();
    }

    const char* toCharArray() const{
        return _str.c_str();
    }

    int find(const NativeString& str) const{
        auto ret = _str.find(str.toCharArray());
        if(ret == std::string::npos)
            return -1;
        else
            return ret;
    }

    int find(const char* c) const{
        auto ret = _str.find(c);
        if(ret == std::string::npos)
            return -1;
        else
            return ret;
    }

    bool ends_with(NativeString const &b) {
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


    friend bool operator== (const NativeString &lhs, const NativeString &rhs){
        return lhs._str == rhs._str;
    }

    friend NativeString operator+ (const NativeString &lhs, const NativeString &rhs){
        return lhs._str + rhs._str;
    }

    NativeString& operator+= (const NativeString& rhs){
        this->_str += rhs._str;
        return *this;
    }


private:
    std::string _str;

};

#endif
#endif //TINY_CLIENT_TCSTRING_H
