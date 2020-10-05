#include "gtest/gtest.h"
#include "mapTraversal.h"

TEST(mapTraversal, findDescendingPaths)
{
    std::vector<std::vector<int>> map = [[1,2,3],
                                         [1,3,2],
                                         [2,1,2]
                                         ];

    std::vector<std::vector<int>> descendingPoints;
    std::vector<std::vector<int>> descendingPointsExpected;
    descendingPoints = findDescendingPaths(map);
    ASSERT_EQUAL(descendingPoints, descendingPointsExpected);
}
