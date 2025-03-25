#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "RGTPQ.h"

TEST_CASE("Testing RGTPQ") {
    RGTPQ pq;
    
    CHECK(pq.empty() == true);

    RGThing red_thing = { RED, "Red Object" };
    RGThing green_thing = { GREEN, "Green Object" };

    SUBCASE("Inserting and checking empty") {
        pq.insert(red_thing);
        CHECK(pq.empty() == false);
    }

    SUBCASE("Inserting Red and Green") {
        pq.insert(red_thing);
        pq.insert(green_thing);
        CHECK(pq.empty() == false);
    }

    SUBCASE("Removing elements") {
        pq.insert(red_thing);
        pq.insert(green_thing);
        RGPair removed = pq.remove();
        CHECK(removed.red_thing.label == "Red Object");
        CHECK(removed.green_thing.label == "Green Object");
    }

    SUBCASE("Removing from empty throws exception") {
        CHECK_THROWS_AS(pq.remove(), std::underflow_error);
    }
}