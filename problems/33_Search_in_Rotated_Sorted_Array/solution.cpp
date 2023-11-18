/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int last = nums.size() - 1;

        int ans = -1;
        while (start <= last)
        {
            int mid = (start + last) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                break;
            }

            if (start == last)
            {
                break;
            }

            // 右側にある
            // ・中央→右で増加かつその間の値
            // ・中央→右で減少かつ左と中央の間にない
            if ((nums[mid] < nums[last] && nums[mid] < target && target <= nums[last]) ||
                (nums[last] < nums[mid] && (target < nums[start] || nums[mid] < target)))
            {
                start = mid + 1;
            }
            // 左側にある
            else
            {
                last = mid - 1;
            }
        }

        return ans;
    }
};
// @lc code=end
