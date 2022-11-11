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
    // Rational<int> x;

    // REQUIRE(x.num() == 0);
    // REQUIRE(x.den() == 1);

    // vector<Rational<long long>> v(10);
    // for (auto r : v)
    // {
    //     REQUIRE(r.num() == 0);
    //     REQUIRE(r.den() == 1);
    // }

    // ostringstream sout;
    // sout << x;

    // REQUIRE(sout.str() == "0/1");
}