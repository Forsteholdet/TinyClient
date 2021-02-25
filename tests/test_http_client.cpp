#include "catch.hpp"
#include "http_client.h"
#include "fake_socket.h"

#include "bourne/json.hpp"
#include "string"

TEST_CASE("initialize object"){

    SECTION("Object is not null"){
        //http_client client;
        //REQUIRE(&client != NULL);
    }

    SECTION("Give network interface to client"){
        //http_client client(new fake_socket());




        //client.get("https://server", "Anders");

//        REQUIRE(response.content == "{'user': 'Anders Aaen:}");
//        REQUIRE(response.header == "{'status_code': 200");


    }


};

TEST_CASE("GET method"){
    fake_socket socket;
    http_client client(&socket);

    SECTION("Get recives input"){
        std::string response = client.get("fake.lol");

        std::string GET = socket.content;

        REQUIRE(GET == "GET");
    }


}
