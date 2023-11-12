/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[s.length()] = true;

        for (int i = s.length() - 1; 0 <= i; --i)
        {
            for (string word : wordDict)
            {
                if (dp[i])
                {
                    break;
                }
                if (i + word.length() <= s.length() && word == s.substr(i, word.length()))
                {
                    dp[i] = dp[i + word.length()];
                }
            }
        }

        return dp[0];
    }
};
// @lc code=end
