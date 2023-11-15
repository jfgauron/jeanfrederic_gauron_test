#include "version.h"
#include <catch.hpp>

TEST_CASE ("Semantic versioning 2.0.0") {
    version v = version("12.345.567-alpha.1+exp.sha123");

    SECTION ( "test version operators" ) {
        REQUIRE(version("1") == version("1"));
        REQUIRE(version("2") != version("1"));
        REQUIRE(version("1") < version("2"));
        REQUIRE(version("2") > version("1"));
        REQUIRE(version("2") >= version("2"));
        REQUIRE(version("1") <= version("1"));
    }

    SECTION ( "version parse parts correctly" ) {
        REQUIRE(v.major() == "12");
        REQUIRE(v.minor() == "345");
        REQUIRE(v.patch() == "567");
        REQUIRE(v.pre_release() == "alpha.1");
        REQUIRE(v.build_tag() == "exp.sha123");
    }

    SECTION ( "incomplete version still supported" ) {
        REQUIRE(version("1").major() == "1");
        REQUIRE(version("1.23").major() == "1");
        REQUIRE(version("1.23").minor() == "23");
        REQUIRE(version("1-alpha.1").pre_release() == "alpha.1");
    }

    SECTION ( "when major version is smaller" ) {
        REQUIRE(version("1") < version("2"));
        REQUIRE(version("2") < version("12"));
        REQUIRE(version("1.5") < version("13"));
        REQUIRE(version("0.9") < version("1.1"));
    }

    SECTION ( "when minor version is smaller" ) {
        REQUIRE(version("1.0") < version("1.1"));
        REQUIRE(version("1.0") < version("1.10"));
    }

    SECTION ( "when patch version is smaller" ) {
        REQUIRE(version("0.0.1") < version("0.0.2"));
        REQUIRE(version("0.0.2") < version("0.0.10"));
    }

    SECTION ( "when compared on prerelease" ) {
        REQUIRE(version("1.0.0-alpha") < version("1.0.0"));
        REQUIRE(version("1.0.0") < version("1.0.1-alpha"));
        REQUIRE(version("1.0.0-alpha") < version("1.0.0-alpha.1"));
        REQUIRE(version("1.0.0-alpha") < version("1.0.0-beta"));
        REQUIRE(version("1.0.0-beta") < version("1.0.0-xyz"));
    }

    SECTION ( "when only build meta is different" ) {
        REQUIRE(version("1.0.0+exp.sha51") == version("1.0.0+xyz"));
    }
}