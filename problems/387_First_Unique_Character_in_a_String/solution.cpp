/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> um{};
        for (char c : s)
        {
            um[c]++;
        }

        for (int i = 0; i < s.length(); ++i)
        {
            if (um.at(s.at(i)) == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
