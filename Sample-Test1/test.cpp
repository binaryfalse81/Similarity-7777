#include "pch.h"
#include "../Project1/sim.cpp"

TEST(SIM_CHECK, SIM_CHECK_001) {
    SimilarityChecker sc;
    int point = sc.check("ABCDE", "ABCDE");
    EXPECT_EQ(point, 100);
}