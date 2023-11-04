/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map{};
        vector<vector<string>> ans{};
        for (auto &str : strs)
        {
            string sorted = str;
            sort(sorted.begin(), sorted.end());

            map[sorted].push_back(str);
        }

        for (auto &val : map)
        {
            ans.push_back(val.second);
        }
        return ans;
    }
};
// @lc code=end
