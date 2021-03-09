#ifndef TINY_CLIENT_HTTP_CLIENT_H
#define TINY_CLIENT_HTTP_CLIENT_H

#include <string>
#include "fake_socket.h"
#include "bourne/json.hpp"
#include "constants.h"
#include <response/response.h>

using namespace std;
namespace tinyclient{

class http_request {


public:
    explicit http_request(tinyclient::t_socket* socket_p) {
        socket = socket_p;
        accept = constants::JSON;
    }
    string host_address;
    string uri;
    string accept;


    string type () const { return _type; };
    bourne::json body () const { return _body; };

    response request(const string& url){
        host_address = find_host_address(url);
        uri = find_uri(url);

        std::string socket_string = get_socket_string();

        if (! body().is_null()){
            socket_string += body().dump();
        }

        socket->send(socket_string);
        std::string response_str = socket->response();

        return response(ok, response_str);
    }

    response get (const string& url){
        _type = "GET";
        return request(url);
    }

private:
    string _type;
    bourne::json _body;
    tinyclient::t_socket *socket; // new socket()


    string get_socket_string(){
        std::stringstream ss;
        ss << _type << " " << uri << " HTTP/1.1\r\n"
           << "Host: " << host_address << "\r\n";
        return ss.str();
    }

    string find_host_address(const string &url) {
        std::string l_host_address = url.substr(0, url.find('/'));

        return l_host_address;
    }

    string find_uri(const string &url) {
        std::string l_uri;
        if (url.find('/') != string::npos)
            l_uri = url.substr(url.find('/'), url.length() - 1);

        return l_uri;
    }


};


}


#endif //TINY_CLIENT_HTTP_CLIENT_H
