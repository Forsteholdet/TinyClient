//
// Created by kaare on 3/19/2021.
//
#include "catch.hpp"
#include "macro/macro_defs.h"

using namespace Catch;

TEST_CASE("Macro type conversion") {

    SECTION("Check type TCstring"){
        TCstring stringOne = "hello";
        TCstring stringTwo = "hello";

        REQUIRE_THAT(stringOne, Equals(stringTwo));


    }



}
