/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include <algorithm>

// @lc code=start
class Solution
{
private:
    double helper(double x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }

        double res = helper(x * x, n / 2);

        return (n % 2) ? x * res : res;
    }

public:
    double myPow(double x, int n)
    {
        long long absN = abs(static_cast<long long>(n));

        double ans = helper(x, absN);

        return (0 <= n) ? ans : 1.0 / ans;
    }
};
// @lc code=end
