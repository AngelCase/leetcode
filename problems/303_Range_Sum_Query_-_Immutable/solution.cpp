/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include <vector>

using namespace std;

// @lc code=start
class NumArray
{
public:
    vector<int> accum;

    NumArray(vector<int> &nums)
    {
        accum.push_back(0);
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            accum.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        return accum[right + 1] - accum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
