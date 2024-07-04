#include "pch.h"
#include "../Project1/sim.cpp"

class SimFixture : public testing::Test
{
public:
    SimilarityChecker sc;

    void CheckLength(string a, string b, int expected)
    {
        int point = sc.CheckStrLength(a, b);
        EXPECT_EQ(point, expected); 
    }
};

TEST_F(SimFixture, SIM_CHECK_001) {
    CheckLength("ABCDE", "ABCDE", 60);
} 

TEST_F(SimFixture, SIM_CHECK_002) {
    CheckLength("ABCD", "ABCDE", 45);
}

TEST_F(SimFixture, SIM_CHECK_003) {
    CheckLength("ABCD", "ABCDEFJKUKKKKK", 0);
}