/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <queue>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    void backtrack(vector<string> &ans, string &&str, int n, int nOpen, int nClose)
    {
        if (str.length() == n * 2)
        {
            ans.push_back(str);
        }

        if (nOpen < n)
        {
            backtrack(ans, str + '(', n, nOpen + 1, nClose);
        }
        if (nClose < nOpen)
        {
            backtrack(ans, str + ')', n, nOpen, nClose + 1);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans{};
        backtrack(ans, "", n, 0, 0);
        return ans;
    }
};
// @lc code=end
