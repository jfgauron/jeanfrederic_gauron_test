#include "overlap.h"
#include <catch.hpp>

TEST_CASE("overlap") {
    SECTION ("1---2----3---4") {
        REQUIRE_FALSE(lines_overlap(1, 2, 3, 4));
    }

    SECTION ("2---3----1---4") {
        REQUIRE(lines_overlap(3, 1, 2, 4));  
    }

    SECTION ("4---3----2---1") {
        REQUIRE_FALSE(lines_overlap(4, 3, 2, 1));
    }

    SECTION ("1---3----2---4") {
        REQUIRE(lines_overlap(1, 3, 2, 4));
    }

    SECTION ("1---3----4---2") {
        REQUIRE(lines_overlap(1, 4, 2, 3));
    }

    SECTION ("with negative number") {
        REQUIRE_FALSE(lines_overlap(1, -1, 2, 3));
    }

    SECTION ("when points touch") {
        REQUIRE(lines_overlap(1, 2, 2, 3));
    }
}