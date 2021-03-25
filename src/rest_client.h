#ifndef TINYCLIENT_REST_CLIENT_H
#define TINYCLIENT_REST_CLIENT_H

#include <string>

using namespace std;

class rest_client {
public:
    rest_client()= default;

    string data;


    size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up){
        return 1;
    }

    void call_api(string url){
        // used to use curl
    }
};


#endif //TINYCLIENT_REST_CLIENT_H
