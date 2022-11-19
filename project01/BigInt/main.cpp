#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <vector>
#include <string>

#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructor")
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

    SUBCASE("non-digit character in string")
    {
        REQUIRE_THROWS_AS(BigInt("-123a"), runtime_error);
    }

    SUBCASE("empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
}

TEST_CASE("Input-output operators")
{
    BigInt x;
    istringstream sin("-1045549757534953498539820483");
    sin >> x;

    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "-1045549757534953498539820483");
}

TEST_CASE("Addition")
{
    ostringstream sout;

    SUBCASE("positive + positive #1")
    {
        BigInt a("193");
        BigInt b("52");
        sout << a + b;
        REQUIRE(sout.str() == "245");
    }

    SUBCASE("positive + positive #2")
    {
        BigInt a("999");
        BigInt b("1");
        sout << a + b;
        REQUIRE(sout.str() == "1000");
    }

    SUBCASE("positive + positive #3")
    {
        // for (int x = 0; x <= 1000; x++)
        // {
        //     for (int y = 0; y <= 1000; y++)
        //     {
        //         BigInt a(std::to_string(x));
        //         BigInt b(std::to_string(y));
        //         sout << a + b;
        //         REQUIRE(sout.str() == std::to_string(x + y));
        //         sout.str("");
        //     }
        // }
    }

    SUBCASE("negative + positive")
    {
    }

    SUBCASE("positive + negative")
    {
    }

    SUBCASE("negative + negative #1")
    {
        BigInt a("-1");
        BigInt b("-999");
        sout << a + b;
        REQUIRE(sout.str() == "-1000");
    }

    SUBCASE("negative + negative #2")
    {
        BigInt a("-193");
        BigInt b("-52");
        sout << a + b;
        REQUIRE(sout.str() == "-245");
    }
}

TEST_CASE("Equality operators")
{
    ostringstream sout;

    SUBCASE("equality operator #1")
    {
        BigInt a("193");
        BigInt b("193");
        REQUIRE(a == b);
    }

    SUBCASE("equality operator #2")
    {
        BigInt a("-193");
        BigInt b("-193");
        REQUIRE(a == b);
    }

    SUBCASE("non-equality operator #1")
    {
        BigInt a("193");
        BigInt b("-193");
        REQUIRE(a != b);
    }

    SUBCASE("non-equality operator #2")
    {
        BigInt a("19333");
        BigInt b("193");
        REQUIRE(a != b);
    }
}

TEST_CASE("Comparison operators")
{
    ostringstream sout;

    SUBCASE("< operator #1")
    {
        BigInt a("19");
        BigInt b("193");
        REQUIRE(a < b);
    }

    SUBCASE("< operator #2")
    {
        BigInt a("-194");
        BigInt b("-193");
        REQUIRE(a < b);
    }

    SUBCASE("> operator #1")
    {
        BigInt a("193");
        BigInt b("19");
        REQUIRE(a > b);
    }

    SUBCASE("> operator #2")
    {
        BigInt a("-99");
        BigInt b("-100");
        REQUIRE(a > b);
    }

    SUBCASE("<= operator #1")
    {
        BigInt a("19");
        BigInt b("193");
        REQUIRE(a <= b);
    }

    SUBCASE("<= operator #2")
    {
        BigInt a("-100");
        BigInt b("-100");
        REQUIRE(a <= b);
    }

    SUBCASE(">= operator #1")
    {
        BigInt a("200");
        BigInt b("200");
        REQUIRE(a >= b);
    }

    SUBCASE(">= operator #2")
    {
        BigInt a("-199");
        BigInt b("-200");
        REQUIRE(a >= b);
    }
}