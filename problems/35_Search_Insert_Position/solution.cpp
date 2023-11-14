/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;
        int last = nums.size() - 1;

        while (1)
        {
            int mid = (start + last) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (target < nums[mid])
            {
                if (mid == start)
                {
                    return start;
                }
                last = mid - 1;
                continue;
            }
            if (mid == last)
            {
                return last + 1;
            }
            start = mid + 1;
        }

        return 0;
    }
};
// @lc code=end
