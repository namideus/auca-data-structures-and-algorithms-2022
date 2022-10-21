#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename C>
string containerToStr(const C &c)
{
    ostringstream sout;
    bool isFirst = true;
    sout << "{";
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sout << ", ";
        }
        sout << e;
        isFirst = false;
    }
    sout << "}";

    return sout.str();
}

TEST_CASE("default constructor")
{
    vector<int> v;

    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}

TEST_CASE("constructor with size")
{
    vector<int> v(5);

    REQUIRE(v.empty() == false);
    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{0, 0, 0, 0, 0}");
}

TEST_CASE("constructor with size and initial value")
{
    vector<int> v(5, -1);

    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{-1, -1, -1, -1, -1}");
}

TEST_CASE("copy constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2 = v; // copy constructor

    REQUIRE(v2.size() == 5);
    REQUIRE(v2[0] == 1);

    v[0] = 1000;
    v2[4] = 66;

    REQUIRE(v[0] == 1000);
    REQUIRE(v2[4] == 66);
}

TEST_CASE("assignment operator")
{
    vector<int> v = {1, 2, 3, 4, 5};

    v[0] = 100;

    REQUIRE(v[0] == 100);
}

TEST_CASE("move constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v1(move(v));

    REQUIRE(containerToStr(v) == "{}");
    REQUIRE(containerToStr(v1) == "{1, 2, 3, 4, 5}");
}

TEST_CASE("move assignment")
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v1 = move(v);

    REQUIRE(containerToStr(v) == "{}");
    REQUIRE(containerToStr(v1) == "{1, 2, 3, 4, 5}");
}

TEST_CASE("subscript operator")
{
    vector<int> v = {1, 2, 3, 4, 5};

    REQUIRE(v[0] == 1);
}

TEST_CASE("method at(index), exception")
{
    vector<int> v = {1, 2, 3, 4, 5};

    REQUIRE_THROWS(v.at(100));
}

TEST_CASE("push_back method")
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 8);
}

TEST_CASE("pop_back method")
{
    vector<int> v = {1, 2, 3, 4, 5};

    v.pop_back();
    v.pop_back();
    v.pop_back();

    REQUIRE(v.size() == 2);
}

TEST_CASE("the work of for (auto element : container) statement with std::vector")
{
    vector<int> v = {1, 2, 3, 4, 5};

    int sum = 0;

    for (auto x : v)
    {
        sum += x;
    }

    REQUIRE(sum == 15);
}

TEST_CASE("methods front(), back()")
{
    vector<int> v = {1, 2, 3, 4, 5};

    REQUIRE(v.front() == 1);

    v.front() = 66;

    REQUIRE(v.front() == 66);

    REQUIRE(v.back() == 5);

    v.back() = 100;

    REQUIRE(v.back() == 100);
}

TEST_CASE("type std::vector<int>::iterator, operators: *it, it->field , ++it, --it, it += n, it-=n, it2 – it1;")
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<string> v2 = {"aaa", "bbb", "ccc"};

    vector<int>::iterator it1 = v.begin();
    REQUIRE(*it1 == 1);

    vector<string>::iterator it = v2.begin();
    REQUIRE(it->size() == 3);

    ++it1;
    REQUIRE(*it1 == 2);

    --it1;
    REQUIRE(*it1 == 1);

    it1 += 4;
    REQUIRE(*it1 == 5);

    it1 -= 4;
    REQUIRE(*it1 == 1);

    vector<int>::iterator it2 = v.end();
    it2--;
    REQUIRE(it2 - it1 == 4);
}

TEST_CASE("methods insert(it, value), insert(it, beg, end)")
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2 = {6, 7, 8};

    v.insert(v.begin() + 1, 7);

    REQUIRE(containerToStr(v) == "{1, 7, 2, 3, 4, 5}");

    v.insert(v.begin(), v2.begin(), v2.end());

    REQUIRE(containerToStr(v) == "{6, 7, 8, 1, 7, 2, 3, 4, 5}");
}

TEST_CASE("methods erase(it), erase(beg, end)")
{
    vector<int> v = {1, 2, 3, 4, 5};

    v.erase(v.begin());

    REQUIRE(containerToStr(v) == "{2, 3, 4, 5}");

    v.erase(v.begin(), v.end());

    REQUIRE(containerToStr(v) == "{}");
}

TEST_CASE("constructor vector(beg, end)")
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2(v1.begin(), v1.end());

    REQUIRE(v2.size() == 5);
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 5}");
}

TEST_CASE("the work of std::reverse algorithm with std::vector")
{
    vector<int> v = {1, 2, 3, 4, 5};

    reverse(v.begin(), v.end());

    REQUIRE(containerToStr(v) == "{5, 4, 3, 2, 1}");
}

TEST_CASE("the work of std::sort algorithm with std::vector")
{
    vector<int> v = {5, 1, 4, 3, 2};

    sort(v.begin(), v.end());

    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
}

TEST_CASE("the work of std::binary_search algorithm with std::vector")
{
    vector<int> v = {1, 2, 3, 4, 5};

    REQUIRE(binary_search(v.begin(), v.end(), 1) == true);

    REQUIRE(binary_search(v.begin(), v.end(), 6) == false);
}

TEST_CASE("the work of std::min_element algorithm with std::vector")
{
    vector<int> v = {1, 2, 3, 4, 5};

    int a = *min_element(v.begin(), v.end());

    REQUIRE(a == 1);
}

TEST_CASE("the work of std::max_element algorithm with std::vector")
{
    vector<int> v = {1, 2, 3, 5, 4};

    int a = *max_element(v.begin(), v.end());

    REQUIRE(a == 5);
}
