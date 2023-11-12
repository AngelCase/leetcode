/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i < dp.size(); ++i)
        {
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }

        return dp.back();
    }
};
// @lc code=end
