#include "catch.hpp"
#include "macro/macro_defs.h"

using namespace Catch;

TEST_CASE("Test TCstring") {

    SECTION("length"){
        TinyString string = "ok";

        REQUIRE(string.length() == 2);
    }

    SECTION("equals"){
        TinyString string = "hello";
        TinyString result = "hello";

        REQUIRE(string == result);
    }

    SECTION("not equals"){
        TinyString string = "hello";
        TinyString cmp = "world";

        REQUIRE((string == cmp) == false);
    }

    SECTION("empty"){
        TinyString string = "";

        REQUIRE(string.empty() == true);
    }

    SECTION("not empty"){
        TinyString string = "hello";

        REQUIRE(string.empty() == false);
    }

    SECTION("substring"){
        TinyString string = "hello world";
        TinyString hello = string.substr(0, 5);

        REQUIRE_THAT(hello.toCharArray(), Equals("hello"));
    }

}
