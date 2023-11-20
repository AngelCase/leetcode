/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int insertPos = 0;
        for (int num : nums)
        {
            if (num != 0)
            {
                nums[insertPos] = num;
                insertPos++;
            }
        }

        while (insertPos < nums.size())
        {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};
// @lc code=end
