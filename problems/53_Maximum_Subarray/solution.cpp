/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53]  Subarray
 */
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp{};
        dp.push_back(nums[0]);
        int curMax = dp[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            dp.push_back(max(nums[i] + dp[i - 1], nums[i]));
            curMax = max(curMax, dp[i]);
        }

        return curMax;
    }
};
// @lc code=end
