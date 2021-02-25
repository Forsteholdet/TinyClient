#ifndef TINYCLIENT_REST_CLIENT_H
#define TINYCLIENT_REST_CLIENT_H

#include <string>
#include "curl/curl.h"

using namespace std;

class rest_client {
public:
    rest_client()= default;

    string data;


    size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up){
        //callback must have this declaration
        //buf is a pointer to the data that curl has for us
        //size*nmemb is the size of the buffer

        for (int c = 0; c<size*nmemb; c++)
        {
            data.push_back(buf[c]);
        }
        return size*nmemb; //tell curl how many bytes we handled
    }

    void call_api(string url){
        CURL *curl;
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://randomuser.me/api/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &rest_client::writeCallback);

        curl_easy_perform(curl);
    }
};


#endif //TINYCLIENT_REST_CLIENT_H
