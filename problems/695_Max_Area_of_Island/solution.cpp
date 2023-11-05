/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int DFS(int area, vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || y < 0 || grid[0].size() <= x || grid.size() <= y || grid[y][x] != 1)
        {
            return area;
        }

        area++;
        grid[y][x] = 0;

        area = DFS(area, grid, x - 1, y);
        area = DFS(area, grid, x, y - 1);
        area = DFS(area, grid, x + 1, y);
        area = DFS(area, grid, x, y + 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max = 0;

        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[0].size(); ++x)
            {
                if (grid[y][x] == 1)
                {
                    int area = DFS(0, grid, x, y);
                    max = std::max(max, area);
                }
            }
        }

        return max;
    }
};
// @lc code=end
