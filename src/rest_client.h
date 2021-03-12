#ifndef TINYCLIENT_REST_CLIENT_H
#define TINYCLIENT_REST_CLIENT_H
#include <Arduino.h>

using namespace std;

class rest_client {
public:
    rest_client()= default;

    String data;


    size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up){

        return size*nmemb; //tell curl how many bytes we handled
    }

    void call_api(String url){
        // used to use curl
    }
};


#endif //TINYCLIENT_REST_CLIENT_H
