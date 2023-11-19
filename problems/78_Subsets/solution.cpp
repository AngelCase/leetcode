/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> sets{{}};

        for (int num : nums)
        {
            int setSize = sets.size();
            for (int i = 0; i < setSize; ++i)
            {
                vector<int> set = sets[i];
                set.push_back(num);
                sets.push_back(set);
            }
        }

        return sets;
    }
};
// @lc code=end
