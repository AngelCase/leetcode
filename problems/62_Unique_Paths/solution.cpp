/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = dp.size() - 2; 0 <= i; --i)
        {
            for (int j = dp[0].size() - 2; 0 <= j; --j)
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};
// @lc code=end
