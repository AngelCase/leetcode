/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        long long ans = nums[0];

        long long curMax = 1;
        long long curMin = 1;
        for (long long num : nums)
        {
            int tmp = curMax;
            curMax = max(num, max(num * curMin, num * curMax));
            curMin = min(num, min(num * curMin, num * tmp));

            ans = max(ans, curMax);
        }

        return ans;
    }
};
// @lc code=end
