#include "pch.h"
#include "../Project1/sim.cpp"

class SimFixture : public testing::Test
{
public:
    SimilarityChecker sc;
    CharChecker cc;

    void CheckLength(string a, string b, int expected)
    {
        int point = sc.CheckStrLength(a, b);
        EXPECT_EQ(point, expected); 
    }

    void CheckAlpha(string a, string b, int expected)
    {
        int point = cc.getCharPoint(a, b);
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

TEST_F(SimFixture, SIM_CHECK_004) {
    CheckAlpha("ABCDE", "ABCDE", 40);
}

TEST_F(SimFixture, SIM_CHECK_005) {
    CheckAlpha("ABCDE", "FGHIJ", 0);
}

TEST_F(SimFixture, SIM_CHECK_006) {
    CheckAlpha("ABD", "AC", 10);
}