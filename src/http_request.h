#ifndef TINY_CLIENT_HTTP_CLIENT_H
#define TINY_CLIENT_HTTP_CLIENT_H

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
    String host_address;
    String uri;
    String accept;


    String type () const { return _type; };
    bourne::json body () const { return _body; };

    response request(const String& url){
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

    response get (const String& url){
        _type = "GET";
        return request(url);
    }

    response post (const String& url){
        _type = "POST";
        return request(url);
    }

    response post (const String& url, bourne::json body){
        _type = "POST";
        _body = body;
        return request(url);
    }

    response del (const String& url){
        _type = "DELETE";
        return request(url);
    }



private:
    String _type;
    bourne::json _body;
    tinyclient::t_socket *socket; // new socket()


    String get_socket_string(){
        std::stringstream ss;
        ss << _type << " " << uri << " HTTP/1.1\r\n"
           << "Host: " << host_address << "\r\n";
        return ss.str();
    }

    String find_host_address(const string &url) {
        std::string l_host_address = url.substr(0, url.find('/'));

        return l_host_address;
    }

    String find_uri(const String &url) {
        std::string l_uri;
        if (url.find('/') != string::npos)
            l_uri = url.substr(url.find('/'), url.length() - 1);

        return l_uri;
    }


};


}


#endif //TINY_CLIENT_HTTP_CLIENT_H
