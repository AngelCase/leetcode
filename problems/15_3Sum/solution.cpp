/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans{};

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            // 固定値の重複を防ぐ
            if (0 < i && nums[i] == nums[i - 1])
            {
                continue;
            }

            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum < 0)
                {
                    low++;
                }
                else if (0 < sum)
                {
                    high--;
                }
                else
                {
                    ans.push_back({nums[i], nums[low], nums[high]});

                    // lowポインタの重複を防ぐ
                    int lowNum = nums[low];
                    while (low < high && nums[low] == lowNum)
                    {
                        low++;
                    }

                    // highポインタの重複を防ぐ
                    int highNum = nums[high];
                    while (low < high && nums[high] == highNum)
                    {
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
