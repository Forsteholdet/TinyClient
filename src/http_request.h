#ifndef TINY_CLIENT_HTTP_CLIENT_H
#define TINY_CLIENT_HTTP_CLIENT_H

#include <string>
#include "fake_socket.h"
#include "bourne/json.hpp"
#include <response/response.h>

using namespace std;
namespace tinyclient{

class http_request {

public:
    explicit http_request(tinyclient::t_socket* socket_p) {
        socket = socket_p; // use heap (new operator)
    }



    response request(const string& url){
        host_address = find_host_address(url);

        socket->send(get_socket_string());
        std::string response_str = socket->response();

        return response(ok, response_str);
    }

    response get (const string& url){
        type = "GET";
        return request(url);
    }


    string host_address;
    string uri;
private:
    string type;
    tinyclient::t_socket *socket; // new socket()




    string get_socket_string(){
        std::stringstream ss;
        ss << type << uri << "HTTP/1.1\r\n"
           << "Host: " << host_address << "\r\n"
           << "Accept: application/json\r\n"
           << "\r\n\r\n";
        return ss.str();
    }

    string find_host_address(const string &url) {
        std::string host_address = url.substr(0, url.find('/'));

        return host_address;
    }
};


}


#endif //TINY_CLIENT_HTTP_CLIENT_H
