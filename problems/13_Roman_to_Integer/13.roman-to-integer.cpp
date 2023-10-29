/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include <vector>
#include <utility>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int func(string &s, string target, int num)
    {
        int add = 0;
        while (s.find(target) == 0)
        {
            s = s.substr(target.length());
            add += num;
        }
        return add;
    }

    int romanToInt(string s)
    {
        std::vector<std::pair<string, int>> arr{
            std::make_pair("M", 1000),
            std::make_pair("CM", 900),
            std::make_pair("D", 500),
            std::make_pair("CD", 400),
            std::make_pair("C", 100),
            std::make_pair("XC", 90),
            std::make_pair("L", 50),
            std::make_pair("XL", 40),
            std::make_pair("X", 10),
            std::make_pair("IX", 9),
            std::make_pair("V", 5),
            std::make_pair("IV", 4),
            std::make_pair("I", 1),
        };

        int answer = 0;
        for (const auto &[target, num] : arr)
        {
            answer += func(s, target, num);
        }

        return answer;
    }
};
// @lc code=end
