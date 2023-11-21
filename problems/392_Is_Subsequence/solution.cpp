/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int idx = 0;
        for (char c : s)
        {
            bool isMatched = false;
            while (idx < t.length())
            {
                if (c == t[idx])
                {
                    isMatched = true;
                    idx++;
                    break;
                }
                idx++;
            }

            if (!isMatched)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
