/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
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
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return ans;
    }
};
// @lc code=end
