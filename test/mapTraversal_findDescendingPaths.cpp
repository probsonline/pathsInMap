#include "gtest/gtest.h"
#include "mapTraversal.h"


TEST(mapTraversal, findDescendingPaths_EmptyTest)
{
    std::vector<std::vector<int>> map = {{}};

    std::vector<std::vector<std::pair<int, int>>>  descendingPointsFound;
    const std::vector<std::vector<std::pair<int, int>>>  descendingPointsExpected = {};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths_SinglePointTest)
{
    std::vector<std::vector<int>> map = {{1}};

    std::vector<std::vector<std::pair<int, int>>>  descendingPointsFound;
    const std::vector<std::vector<std::pair<int, int>>>  descendingPointsExpected = {{{0,0}}};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}









/*
TEST(mapTraversal, findDescendingPaths_SinglePathTest)
{
    std::vector<std::vector<int>> map = {{5,4,3,2,1}};

    std::vector<std::vector<int>> descendingPointsFound;
    std::vector<std::vector<int>> descendingPointsExpected = {{5,4,3,2,1}};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths_FlatTerrainTest)
{
    std::vector<std::vector<int>> map = {{1,1}, {1,1}};

    std::vector<std::vector<int>> descendingPointsFound;
    std::vector<std::vector<int>> descendingPointsExpected = {{1}, {1}, {1,1}};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths1)
{
    std::vector<std::vector<int>> map = {{1,2,3},
                                         {1,3,2},
                                         {2,1,2}
                                         };

    std::vector<std::vector<int>> descendingPointsFound;
    std::vector<std::vector<int>> descendingPointsExpected = {{1},{2},{3}, {3,2,1}, {3,2}, {3,1}, {3,3}};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths2)
{
    std::vector<std::vector<int>> map = {{0,0,0},
                                         {0,1,0},
                                         {0,0,0}
                                         };

    std::vector<std::vector<int>> descendingPointsFound;
    std::vector<std::vector<int>> descendingPointsExpected = {{1,0}};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}
*/