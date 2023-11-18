/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> um{};
        int left = 0;
        int right = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); ++right)
        {
            if (um.count(s[right]) == 0 || um[s[right]] < left)
            {
                maxLen = max(maxLen, right - left + 1);
            }
            else
            {
                // 重複が発生した1つ次から探し始める
                left = um[s[right]] + 1;
            }
            um[s[right]] = right;
        }

        return maxLen;
    }
};
// @lc code=end
