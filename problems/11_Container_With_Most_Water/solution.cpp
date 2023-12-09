/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while (l < r)
        {
            int lowerHeight = min(height[l], height[r]);
            ans = max(ans, lowerHeight * (r - l));

            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return ans;
    }
};
// @lc code=end
