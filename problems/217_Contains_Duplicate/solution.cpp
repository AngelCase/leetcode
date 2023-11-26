/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> us{};
        for (int num : nums)
        {
            if (us.find(num) != us.end())
            {
                return true;
            }
            us.emplace(num);
        }

        return false;
    }
};
// @lc code=end
