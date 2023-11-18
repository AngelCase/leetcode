/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        int l = 1;
        int r = pow(2, n - 1);
        int cur = 0;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (mid < k)
            {
                l = mid + 1;
                cur = 1 - cur;
            }
            else
            {
                r = mid;
            }
        }

        return cur;
    }
};
// @lc code=end
