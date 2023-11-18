/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int min = 5000;
        int start = 0;
        int last = nums.size() - 1;

        while (1)
        {
            int mid = (start + last) / 2;
            min = std::min(min, nums[mid]);
            if (last <= start)
            {
                break;
            }
            if (nums[mid] < nums[last])
            {
                last = mid - 1;
                continue;
            }
            start = mid + 1;
        }
        return min;
    }
};
// @lc code=end
