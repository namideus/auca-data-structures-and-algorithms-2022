#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>
#include <sstream>

#include "Rational.hpp"

using namespace std;

TEST_CASE("Default constructor")
{
    Rational<int> x;

    REQUIRE(x.num() == 0);
    REQUIRE(x.den() == 1);

    vector<Rational<long long>> v(10);
    for (auto r : v)
    {
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    ostringstream sout;
    sout << x;

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Constructor Rational(num, den)")
{
    SUBCASE("denominator is equal to zero")
    {
        REQUIRE_THROWS_AS(Rational<int>(5, 0), std::runtime_error);
    }
}