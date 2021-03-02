#include <response/response.h>
#include "catch.hpp"
#include "http_request.h"
#include "fake_socket.h"

#include "bourne/json.hpp"
#include "string"


TEST_CASE("HTTP Request"){
    auto *socket = new fake_socket();
    http_request client(socket);

    SECTION("Initialise client object with empty string"){
        REQUIRE(true);
    }

    SECTION ("Request string have method"){

        client.get("fake.lol");
        std::string content = socket->content;

        REQUIRE( content.substr(0, 3) == "GET");
    }

    SECTION("Find addresse only have baseurl"){
        std::string baseurl = "facebook.com";

        client.request(baseurl);

        REQUIRE(client.host_address == baseurl);
    }

    SECTION("Find host addresse with url and uri"){
        std::string baseurl = "facebook.com";

        client.request(baseurl + "/users");

        REQUIRE(client.host_address == baseurl);
    }

    SECTION("Find uri with url"){
        std::string baseurl = "facebook.com";
        auto uri = "/users";

        client.request(baseurl + uri);

        REQUIRE(client.uri == uri);
    }

    delete socket;
};

TEST_CASE("GET method"){
    auto *socket = new fake_socket();
    tinyclient::http_request client(socket);

    SECTION("receives input"){
        response rsp = client.get("fake.lol");

        std::string GET = socket->content.substr(0,3);

        REQUIRE(GET == "GET");
    }

    SECTION("options"){
        std::string url = "fake.lol/costumers/1";
        response rsp = client.get(url);
        std::string content = socket->content;
        std::string content_url = content.erase(0,4);

        REQUIRE(content == content_url);
    }

    SECTION("Get returns a response"){


        std::string url = "fake.lol";

        response response = client.get(url);
    }

    delete socket;
}



