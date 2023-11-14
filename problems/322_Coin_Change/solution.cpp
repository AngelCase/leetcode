/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        sort(coins.begin(), coins.end());

        for (int i = 1; i <= amount; ++i)
        {
            for (int coin : coins)
            {
                if (i - coin < 0)
                {
                    break;
                }

                if (dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i - coin] + 1, dp[i]);
                }
            }
        }

        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
// @lc code=end
