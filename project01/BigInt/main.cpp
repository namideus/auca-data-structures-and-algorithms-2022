#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <vector>
#include <string>

#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructors")
{
    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");
}

TEST_CASE("Default constructor with a string parameter")
{
    BigInt x("-12765876876764764876764648484864848746448764787864");
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "-12765876876764764876764648484864848746448764787864");

    SUBCASE("throw runtime_error")
    {
        REQUIRE_THROWS_AS(BigInt("-123a"), runtime_error);
    }
}