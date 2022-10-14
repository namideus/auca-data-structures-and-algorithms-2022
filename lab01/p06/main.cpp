#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>
#include <iostream>

using namespace std;

TEST_CASE("test case back()")
{
    vector<int> v = {1,2,3,4,5};
    vector<int> other = {34,21,30,49,53};

    REQUIRE_EQ(v.back(), 5);

    v.back() = 100;

    REQUIRE_EQ(v.back(), 100);
}

TEST_CASE("test case front()")
{
    vector<int> v = {1,2,3,4,5};
    vector<int> other = {34,21,30,49,53};

    REQUIRE_EQ(v.front(),1);

    v.front() = 66;

    REQUIRE_EQ(v.front(),66);
}

TEST_CASE("test case pop_back()")
{
    vector<int> v = {1,2,3,4,5};

    REQUIRE_EQ(v.back(),5);

    v.pop_back();

    REQUIRE_EQ(v.back(),4);
}

TEST_CASE("test case operator[]")
{
    vector<int> v = {1,2,3,4,5};

    REQUIRE_EQ(v[0], 1);

    v[0]=77;

    REQUIRE_EQ(v[0], 77);
}

TEST_CASE("test case at()")
{
    vector<int> v = {1,2,3,4,5};

    REQUIRE_THROWS(v.at(100));
}

TEST_CASE("test case operator[]")
{
    vector<int> v = {1,2,3,4,5};
    vector<int> other = {34,21,30,49,53};

    v = other;

    CHECK(v == other);
}
