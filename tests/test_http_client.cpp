#include <response/response.h>
#include <constants.h>
#include "catch.hpp"
#include "http_request.h"
#include "fake_socket.h"

#include "bourne/json.hpp"
#include "string"
using namespace Catch;


// bugs
//// make two request in a row;

TEST_CASE("HTTP Request"){
    auto *socket = new fake_socket();
    http_request client(socket);

    SECTION("Initialise client object with empty string"){
        REQUIRE(true);
    }

    SECTION ("Request string have method"){

        client.get("tinyclient.com");
        std::string content = socket->content;

        REQUIRE_THAT(content ,StartsWith("GET"));
    }

    SECTION("Find address only have baseurl"){
        std::string baseurl = "tinyclient.com";

        client.request(baseurl);

        REQUIRE(client.host_address == baseurl);
    }

    SECTION("Find host address with url and uri"){
        std::string baseurl = "tinyclient.com";

        client.request(baseurl + "/users");

        REQUIRE(client.host_address == baseurl);
    }

    SECTION("If no uri, make it empty"){
        std::string baseurl = "tinyclient.com";

        client.request(baseurl);

        REQUIRE(client.uri.empty());
    }

    SECTION("Find uri with url"){
        std::string baseurl = "tinyclient.com";
        auto uri = "/users";

        client.request(baseurl + uri);

        REQUIRE(client.uri == uri);
    }

    SECTION("Make a request with uri and host"){

        client.get("tinyclient.com/users?page=lol");

        auto full_request = client.type() + " /users?page=lol HTTP/1.1\r\n"
                            "Host: tinyclient.com\r\n";

        REQUIRE_THAT(socket->content, Equals(full_request));
    }

    SECTION("Reqeust standard accept is application/json"){

        client.request("tinyclient.com");

        REQUIRE_THAT(client.accept, Equals(constants::JSON));
    }


    delete socket;
};

TEST_CASE("GET"){
    auto *socket = new fake_socket();
    tinyclient::http_request client(socket);

    SECTION("receives input"){
        response rsp = client.get("tinyclient.com");

        REQUIRE_THAT(socket->content, StartsWith("GET"));
    }


    SECTION("Get returns a response"){
        std::string url = "tinyclient.com";

        response response = client.get(url);
    }

    delete socket;
}

TEST_CASE("POST"){
    auto *socket = new fake_socket();
    tinyclient::http_request client(socket);

    SECTION("receives input"){
        response rsp = client.post("tinyclient.com");
        REQUIRE_THAT(socket->content, StartsWith("POST"));
    }

    SECTION("Accept body with post request"){

        bourne::json body = {"Id","1"};

        response rsp = client.post("tinyclient.com", body);

        REQUIRE(client.body() == body);
    }

    SECTION("Socket receives body, in the end of request"){
        bourne::json body = {"Id","1"};

        response rsp = client.post("tinyclient.com", body);

        REQUIRE_THAT(socket->content, EndsWith(body.dump()));
    }

    delete socket;
}

TEST_CASE("DELETE") {
    auto *socket = new fake_socket();
    tinyclient::http_request client(socket);

    SECTION("Check type"){
        response rsp = client.del("tinyclient.com");

        REQUIRE_THAT(socket->content, StartsWith("DELETE"));
    }

    delete socket;
}