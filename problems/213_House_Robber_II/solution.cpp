/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
private:
    int calcMax(vector<int> &&nums)
    {
        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums)
        {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }

        return prev1;
    }

public:
    int
    rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int max1 = calcMax(vector<int>(nums.begin(), nums.end() - 1));
        int max2 = calcMax(vector<int>(nums.begin() + 1, nums.end()));
        return max(max1, max2);
    }
};
// @lc code=end
