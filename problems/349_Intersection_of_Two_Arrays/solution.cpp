/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set{};

        for (const auto num : nums1)
        {
            set.emplace(num);
        }

        unordered_set<int> ansSet{};
        for (const auto num : nums2)
        {
            if (0 < set.count(num))
            {
                ansSet.emplace(num);
            }
        }

        vector<int> ans{};
        for (auto val : ansSet)
        {
            ans.push_back(val);
        }

        return ans;
    }
};
// @lc code=end
