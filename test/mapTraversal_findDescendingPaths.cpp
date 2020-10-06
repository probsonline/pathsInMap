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

// Values in negative will be treated as below sea level and so can't be part of descending path to ocean
TEST(mapTraversal, findDescendingPaths_InvalidSinglePointTest)
{
    std::vector<std::vector<int>> map = {{-1}};

    std::vector<std::vector<std::pair<int, int>>>  descendingPointsFound;
    const std::vector<std::vector<std::pair<int, int>>>  descendingPointsExpected = {};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths_SinglePointTest)
{
    std::vector<std::vector<int>> map = {{5}};

    std::vector<std::vector<std::pair<int, int>>>  descendingPointsFound;
    const std::vector<std::vector<std::pair<int, int>>>  descendingPointsExpected = {{{0,0}}};

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths_FlatTerrainTest)
{
    std::vector<std::vector<int>> map = {{1,1}, {1,1}};

    std::vector<std::vector<std::pair<int, int>>>  descendingPointsFound;
    const std::vector<std::vector<std::pair<int, int>>>  descendingPointsExpected = {
        // All descending paths towards pacific 
        { {0,0} },
        { {1,0} },
        { {0,1}, {0,0} },
        { {0,1}, {1,0} },
        { {1,1}, {0,0} },
        { {1,1}, {1,0} },

        // All descending Path towards atlantic
        { {0,1} },
        { {1,1} },
        { {0,0}, {0,1} },
        { {0,0}, {1,1} },
        { {1,0}, {0,1} },
        { {1,0}, {1,1} },
        };

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths_OneHighPointTest)
{
    std::vector<std::vector<int>> map = {
        {0,0,0}, 
        {0,5,0}, 
        {0,0,0} 
        };

    std::vector<std::vector<std::pair<int, int>>>  descendingPointsFound;
    const std::vector<std::vector<std::pair<int, int>>>  descendingPointsExpected = {
        // All descending paths towards pacific     
        // (Note: Apparently going to atlantic from mid and then back to pacific is also a path but we'll not count those)
        { {0,0} },
        { {1,0} },
        { {2,0} },
        { {1,1}, {0,0} },
        { {1,1}, {1,0} },
        { {1,1}, {2,0} },
        { {1,1}, {1,0}, {0,0} },
        { {1,1}, {2,0}, {0,0} },

        // All descending Path towards atlantic
        // (Note: Apparently going to pacific from mid and then back to atlantic is also a path but we'll not count those)
        { {2,0} },
        { {2,1} },
        { {2,2} },
        { {1,1}, {0,2} },
        { {1,1}, {1,2} },
        { {1,1}, {2,2} },
        { {1,1}, {1,0}, {2,0} },
        { {1,1}, {2,0}, {2,2} }
        };

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}

TEST(mapTraversal, findDescendingPaths_MultiHighPointTest)
{
    std::vector<std::vector<int>> map = {
        {0,3,0}, 
        {0,0,0}, 
        {0,2,0} 
        };

    std::vector<std::vector<std::pair<int, int>>>  descendingPointsFound;
    const std::vector<std::vector<std::pair<int, int>>>  descendingPointsExpected = {
        // All descending paths towards pacific     
        // (Note: Apparently going to atlantic from mid and then back to pacific is also a path but we'll not count those)
        { {0,0} },
        { {1,0} },
        { {2,0} },
        { {1,1}, {0,0} },
        { {1,1}, {1,0} },
        { {1,1}, {2,0} },

        { {0,1}, {0,0} },
        { {0,1}, {1,0} },
        { {2,1}, {2,0} },
        { {2,1}, {1,0} },

        { {0,1}, {1,1}, {0,0} },
        { {0,1}, {1,1}, {1,0} },
        { {0,1}, {1,1}, {2,0} },

        { {2,1}, {1,1}, {0,0} },
        { {2,1}, {1,1}, {1,0} },
        { {2,1}, {1,1}, {2,0} },

        // All descending Path towards atlantic
        // (Note: Apparently going to pacific from mid and then back to atlantic is also a path but we'll not count those)
        { {2,0} },
        { {2,1} },
        { {2,2} },
        { {1,1}, {0,2} },
        { {1,1}, {1,2} },
        { {1,1}, {2,2} },

        { {0,1}, {0,2} },
        { {0,1}, {1,2} },
        { {2,1}, {2,2} },
        { {2,1}, {1,2} },

        { {0,1}, {1,1}, {0,2} },
        { {0,1}, {1,1}, {1,2} },
        { {0,1}, {1,1}, {2,2} },

        { {2,1}, {1,1}, {0,2} },
        { {2,1}, {1,1}, {1,2} },
        { {2,1}, {1,1}, {2,2} }
        };

    descendingPointsFound = findDescendingPaths(map);
    EXPECT_EQ(descendingPointsFound, descendingPointsExpected);
}
