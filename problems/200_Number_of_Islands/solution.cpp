/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    void check(vector<vector<char>> &grid, int x, int y)
    {
        grid[y][x] = '#';
        if (0 <= x - 1 && grid[y][x - 1] == '1')
        {
            check(grid, x - 1, y);
        }
        if (0 <= y - 1 && grid[y - 1][x] == '1')
        {
            check(grid, x, y - 1);
        }
        if (x + 1 < grid[0].size() && grid[y][x + 1] == '1')
        {
            check(grid, x + 1, y);
        }
        if (y + 1 < grid.size() && grid[y + 1][x] == '1')
        {
            check(grid, x, y + 1);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;

        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[0].size(); ++x)
            {
                if (grid[y][x] == '1')
                {
                    count++;
                    check(grid, x, y);
                }
            }
        }

        return count;
    }
};
// @lc code=end
