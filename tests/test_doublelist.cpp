#include "catch.hpp"
#include "DoubleList.cpp"

TEST_CASE("DoubleList: Basic Operations", "[DoubleList]") {
    DoubleList<int> list;

    SECTION("List is initially empty") {
        REQUIRE(list.empty());
        REQUIRE(list.size() == 0);
    }

    SECTION("Push front operation") {
        list.push_front(10);
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 10);

        list.push_front(20);
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 20);
    }

    SECTION("Push back operation") {
        list.push_back(10);
        REQUIRE(list.size() == 1);
        REQUIRE(list.back() == 10);

        list.push_back(20);
        REQUIRE(list.size() == 2);
        REQUIRE(list.back() == 20);
    }

    SECTION("Pop front operation") {
        list.push_back(10);
        list.push_back(20);
        REQUIRE(list.size() == 2);

        list.pop_front();
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 20);
    }

    SECTION("Pop back operation") {
        list.push_back(10);
        list.push_back(20);
        REQUIRE(list.size() == 2);

        list.pop_back();
        REQUIRE(list.size() == 1);
        REQUIRE(list.back() == 10);
    }

    SECTION("Insert operation") {
        list.push_back(10);
        list.push_back(30);
        list.insert(1, 20);
        REQUIRE(list.size() == 3);

        list.pop_front();
        REQUIRE(list.front() == 20);
    }

    SECTION("Remove specific value") {
        list.push_back(10);
        list.push_back(20);
        list.push_back(20);
        list.push_back(30);
        list.remove(20);
        REQUIRE(list.size() == 2);
        REQUIRE(list.back() == 30);
    }
}