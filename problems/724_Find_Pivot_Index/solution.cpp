/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> accum{};
        accum.push_back(0);
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
            accum.push_back(sum);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            int leftSum = accum[i];
            int rightSum = accum.back() - accum[i + 1];
            if (leftSum == rightSum)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
