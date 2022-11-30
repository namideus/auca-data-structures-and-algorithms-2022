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
        REQUIRE_THROWS_AS(BigInt("--123"), runtime_error);
    }

    SUBCASE("empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
}

TEST_CASE("Default constructor with an integer parameter")
{
    ostringstream sout;

    SUBCASE("positive integer")
    {
        BigInt x(123456789);
        sout << x;
        REQUIRE(sout.str() == "123456789");
    }

    SUBCASE("negative integer")
    {
        BigInt x(-123456789);
        sout << x;
        REQUIRE(sout.str() == "-123456789");
    }
}

TEST_CASE("Input operator")
{
    ostringstream sout;
    SUBCASE("correct input #1")
    {
        istringstream sinp("123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }
    SUBCASE("correct input #2")
    {
        istringstream sinp("  123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }
    SUBCASE("correct input #3")
    {
        istringstream sinp("123x123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
        char ch;
        sinp >> ch;
        REQUIRE(ch == 'x');
    }
    SUBCASE("correct input #4")
    {
        istringstream sinp("   -123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == -123);
    }
    SUBCASE("correct input #5")
    {
        istringstream sinp("   +123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }
    SUBCASE("incorrect input #1")
    {
        istringstream sinp("+ 123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }
    SUBCASE("incorrect input #2")
    {
        istringstream sinp("++123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }
    SUBCASE("incorrect input #3")
    {
        istringstream sinp("hello");
        BigInt x;
        char ch;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
        sinp.clear();
        sinp >> ch;
        REQUIRE(ch == 'h');
    }
    SUBCASE("incorrect input #4")
    {
        istringstream sinp("");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(sinp.eof());
        REQUIRE(x == 0);
    }
}

TEST_CASE("Addition operator")
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

TEST_CASE("Subtraction")
{
    ostringstream sout;

    SUBCASE("positive - positive #1")
    {
        BigInt a("191");
        BigInt b("52");
        sout << a - b;
        REQUIRE(sout.str() == "139");
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

    SUBCASE("less than operator #1")
    {
        BigInt a("19");
        BigInt b("193");
        REQUIRE(a < b);
    }

    SUBCASE("less than operator #2")
    {
        BigInt a("-194");
        BigInt b("-193");
        REQUIRE(a < b);
    }

    SUBCASE("less than operator #3")
    {
        BigInt a("-192");
        BigInt b("-193");
        REQUIRE_FALSE(a < b);
    }

    SUBCASE("less than operator #4")
    {
        for (int i = -100; i <= 100; i++)
        {
            for (int j = -100; j <= 100; j++)
            {
                if (i < j)
                {
                    BigInt a(std::to_string(i));
                    BigInt b(std::to_string(j));
                    REQUIRE(a < b);
                }
            }
        }
    }

    SUBCASE("greater than operator #1")
    {
        BigInt a("193");
        BigInt b("19");
        REQUIRE(a > b);
    }

    SUBCASE("greater than operator #2")
    {
        BigInt a("-99");
        BigInt b("-100");
        REQUIRE(a > b);
    }

    SUBCASE("greater than operator #3")
    {
        for (int i = -100; i <= 100; i++)
        {
            for (int j = -100; j <= 100; j++)
            {
                if (i >= j)
                {
                    BigInt a(std::to_string(i));
                    BigInt b(std::to_string(j));
                    REQUIRE(a >= b);
                }
            }
        }
    }

    SUBCASE("less than or equal operator #1")
    {
        BigInt a("19");
        BigInt b("193");
        REQUIRE(a <= b);
    }

    SUBCASE("less than or equal operator #2")
    {
        BigInt a("-100");
        BigInt b("-100");
        REQUIRE(a <= b);
    }

    SUBCASE("greater than or equal operator #1")
    {
        BigInt a("200");
        BigInt b("200");
        REQUIRE(a >= b);
    }

    SUBCASE("greater than or equal operator #2")
    {
        BigInt a("-199");
        BigInt b("-200");
        REQUIRE(a >= b);
    }
}

TEST_CASE("Prefix and postfix increment and decrement")
{
    ostringstream sout;

    SUBCASE("Postfix increment")
    {
        BigInt a("100");
        a++;
        sout << a;
        REQUIRE(sout.str() == "101");
    }

    SUBCASE("Prefix increment")
    {
        BigInt a("101");
        ++a;
        sout << a;
        REQUIRE(sout.str() == "102");
    }
}

TEST_CASE("Abs() function")
{
    ostringstream sout;

    SUBCASE("abs(positive)")
    {
        istringstream sinp("123");
        BigInt x;
        sinp >> x;
        BigInt r = BigInt::abs(x);
        REQUIRE(r == 123);
    }

    SUBCASE("abs(negative)")
    {
        istringstream sinp("-123");
        BigInt x;
        sinp >> x;
        BigInt r = BigInt::abs(x);
        REQUIRE(r == 123);
    }
}