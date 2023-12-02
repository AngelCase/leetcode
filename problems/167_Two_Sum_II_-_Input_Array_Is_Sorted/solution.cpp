/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0;
        int high = numbers.size() - 1;

        while (1)
        {
            long long sum = numbers[low] + numbers[high];
            if (sum == target)
            {
                break;
            }

            if (sum < target)
            {
                low++;
            }
            else if (target < sum)
            {
                high--;
            }
        }

        return {low + 1, high + 1};
    }
};
// @lc code=end
