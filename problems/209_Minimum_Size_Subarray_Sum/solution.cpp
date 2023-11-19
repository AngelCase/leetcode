/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minLen = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            right++;
            while (target <= sum)
            {
                minLen = min(minLen, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
// @lc code=end
