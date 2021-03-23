//
// Created by kaare on 3/19/2021.
//
#include "catch.hpp"
#include "macro/macro_defs.h"

using namespace Catch;

TEST_CASE("Test TCstring") {

    SECTION("length"){
        TCstring string = "ok";

        REQUIRE(string.length() == 2);
    }

    SECTION("equals"){
        TCstring string = "hello";
        TCstring result = "hello";

        REQUIRE(string == result);
    }

    SECTION("not equals"){
        TCstring string = "hello";
        TCstring cmp = "world";

        REQUIRE((string == cmp) == false);
    }

    SECTION("empty"){
        TCstring string = "";

        REQUIRE(string.empty() == true);
    }

    SECTION("not empty"){
        TCstring string = "hello";

        REQUIRE(string.empty() == false);
    }

    SECTION("substring"){
        TCstring string = "hello world";
        TCstring hello = string.substr(0,5);

        REQUIRE_THAT(hello.str.c_str(), Equals("hello"));
    }

}
