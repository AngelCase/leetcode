/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return vector<vector<int>>{nums};
        }

        vector<vector<int>> ans{};

        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            nums.erase(nums.begin() + i);

            for (vector<int> &vec : permute(nums))
            {
                vec.insert(vec.begin(), num);
                ans.push_back(vec);
            }

            nums.insert(nums.begin() + i, num);
        }

        return ans;
    }
};
// @lc code=end
