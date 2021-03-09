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

        client.get("fake.lol");
        std::string content = socket->content;

        REQUIRE_THAT(content ,StartsWith("GET"));
    }

    SECTION("Find address only have baseurl"){
        std::string baseurl = "facebook.com";

        client.request(baseurl);

        REQUIRE(client.host_address == baseurl);
    }

    SECTION("Find host address with url and uri"){
        std::string baseurl = "facebook.com";

        client.request(baseurl + "/users");

        REQUIRE(client.host_address == baseurl);
    }

    SECTION("If no uri, make it empty"){
        std::string baseurl = "facebook.com";

        client.request(baseurl);

        REQUIRE(client.uri.empty());
    }

    SECTION("Find uri with url"){
        std::string baseurl = "facebook.com";
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

        REQUIRE(GET == "GET");
    }


    SECTION("Get returns a response"){
        std::string url = "tinyclient.com";

        response response = client.get(url);
    }

    delete socket;
}
