/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include <string>

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        long long reversed = 0;
        long long xCopy = x;
        while (xCopy != 0)
        {
            reversed = reversed * 10 + xCopy % 10;
            xCopy /= 10;
        }

        return x == reversed;
    }
};
// @lc code=end
