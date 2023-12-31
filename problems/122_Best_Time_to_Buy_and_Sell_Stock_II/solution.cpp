/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            ans += max(prices[i] - prices[i - 1], 0);
        }

        return ans;
    }
};
// @lc code=end
