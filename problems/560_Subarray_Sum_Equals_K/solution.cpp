/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> um{};
        um[0] = 1;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums.at(i);
            if (um.find(sum - k) != um.end())
            {
                ans += um.at(sum - k);
            }
            um[sum]++;
        }

        return ans;
    }
};
// @lc code=end
