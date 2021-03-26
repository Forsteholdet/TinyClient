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
    TinyString host_address = "";
    TinyString uri = "";
    TinyString accept = "";


    TinyString type () const { return _type; };
    bourne::json body () const { return _body; };

    response request(const TinyString& url){
        host_address = find_host_address(url);
        uri = find_uri(url);

        TinyString socket_string = get_socket_string();

        if (! body().is_null()){
            socket_string += body().dump().c_str();
        }

        socket->send(socket_string);
        TinyString response_str = socket->response();

        return response(ok, response_str);
    }

    response get (const TinyString& url){
        _type = "GET";
        return request(url);
    }

    response post (const TinyString& url){
        _type = "POST";
        return request(url);
    }

    response post (const TinyString& url, bourne::json body){
        _type = "POST";
        _body = body;
        return request(url);
    }

    response del (const TinyString& url){
        _type = "DELETE";
        return request(url);
    }



private:
    TinyString _type = "";
    bourne::json _body;
    tinyclient::t_socket *socket; // new socket()


    TinyString get_socket_string(){
        TinyString ss = "";
        ss = _type + " " + uri + " HTTP/1.1\r\n"
           + "Host: " + host_address + "\r\n";
        return ss;
    }

    TinyString find_host_address(const NativeString &url) {
        TinyString l_host_address = url.substr(0, url.find("/"));

        return l_host_address;
    }

    TinyString find_uri(const TinyString &url) {
        TinyString l_uri = "";
        if (url.find("/") != -1)
            l_uri = url.substr(url.find("/"), url.length() - 1);

        return l_uri;
    }

};

}


#endif //TINY_CLIENT_HTTP_CLIENT_H
