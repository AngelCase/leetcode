/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        vector<vector<long long>> dp(h, vector<long long>(w, 0));

        // 端を初期化
        for (int x = w - 1; 0 <= x; --x)
        {
            if (obstacleGrid[h - 1][x] == 1)
            {
                break;
            }
            dp[h - 1][x] = 1;
        }
        for (int y = h - 1; 0 <= y; --y)
        {
            if (obstacleGrid[y][w - 1] == 1)
            {
                break;
            }
            dp[y][w - 1] = 1;
        }

        // 端以外の計算
        for (int x = w - 2; 0 <= x; --x)
        {
            for (int y = h - 2; 0 <= y; --y)
            {
                if (obstacleGrid[y][x])
                {
                    dp[y][x] = 0;
                    continue;
                }
                dp[y][x] = dp[y + 1][x] + dp[y][x + 1];
            }
        }

        return dp[0][0];
    }
};
// @lc code=end
