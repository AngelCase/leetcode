/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> dp(size, 1);

        int ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// @lc code=end
