/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <unordered_map>

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map{};
        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (map.count(complement))
            {
                return {map.at(complement), i};
            }
            map.emplace(nums[i], i);
        }
        return {};
    }
};
// @lc code=end
