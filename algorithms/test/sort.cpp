#include "catch.hpp"
#include <iostream>
#include "sort.hpp"

TEST_CASE("Empty vector is sorted", "[insertion_sort]")
{
    std::vector<int> in;
    std::vector<int> out;
    insertion_sort(in);
    REQUIRE(in == out);
}

TEST_CASE("One element is always sorted", "[insertion_sort]")
{
    std::vector<int> in {1};
    std::vector<int> out {1};
    insertion_sort(in);
    REQUIRE(in == out);
}

TEST_CASE("Two elements ordered ascending is sorted", "[insertion_sort]")
{
    std::vector<int> in {1, 2};
    std::vector<int> out {1, 2};
    insertion_sort(in);
    REQUIRE(in == out);
}

TEST_CASE("Two elements ordered descending are reversed upon sort", "[insertion_sort]")
{
    std::vector<int> in {2, 1};
    std::vector<int> out {1, 2};
    insertion_sort(in);
    REQUIRE(in == out);
}

TEST_CASE("Three mixed up elements get sorted", "[insertion_sort]")
{
    std::vector<int> in {3, 1, 2};
    std::vector<int> out {1, 2, 3};
    insertion_sort(in);
    REQUIRE(in == out);
}

struct Int
{
    explicit Int(int _value)
    : value(_value)
    {}

    Int& operator=(Int const& r)
    {
        ++assignment_count;
        value = r.value;
        return *this;
    }

    bool operator<(Int const& r) const
    {
        ++comparison_count;
        return value < r.value;
    }

    bool operator==(Int const& r) const
    {
        return value == r.value;
    }

    friend std::ostream& operator<<(std::ostream& os, Int i)
    {
        os << i.value;
        return os;
    }
    
    int value;
    static int comparison_count;
    static int assignment_count;
};

int Int::assignment_count = 0;
int Int::comparison_count = 0;

Int operator ""_i(unsigned long long i)
{
    return Int(i);
}

TEST_CASE("Complexity of insertion sort is quadratic")
{
    std::vector<Int> in {5_i, 4_i, 3_i, 2_i, 1_i};
    std::vector<Int> out {1_i, 2_i, 3_i, 4_i, 5_i};
    insertion_sort<Int>(in);
    REQUIRE(in == out);
    std::size_t n = in.size();
    REQUIRE(Int::comparison_count == n*(n-1)/2);
    REQUIRE(Int::assignment_count == n*(n-1));
}