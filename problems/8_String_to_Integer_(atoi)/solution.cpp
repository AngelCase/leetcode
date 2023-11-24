/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
private:
    int skipSpace(string &s, int idx)
    {
        while (s[idx] == ' ')
        {
            idx++;
        }
        return idx;
    }

    int skipSign(string &s, int idx)
    {
        if (s[idx] == '+' || s[idx] == '-')
        {
            idx++;
        }

        return idx;
    }

    string substrDigits(string &s, int idx)
    {
        const unordered_set<char>
            digits = {
                '0',
                '1',
                '2',
                '3',
                '4',
                '5',
                '6',
                '7',
                '8',
                '9',
            };
        string digitsStr = "";
        while (idx < s.length() && digits.find(s[idx]) != digits.end())
        {
            digitsStr += s[idx];
            idx++;
        }
        return digitsStr;
    }

    long long atoll(string &digitsStr, bool isNegative)
    {
        const long long INT_MAX_ABS = static_cast<long long>(INT_MAX) + 1;
        long long num = 0LL;
        for (char c : digitsStr)
        {
            num = num * 10 + c - '0';
            if (INT_MAX_ABS < num)
            {
                num = INT_MAX_ABS;
                break;
            }
        }

        if (!isNegative && num == INT_MAX_ABS)
        {
            num = INT_MAX;
        }

        return isNegative ? -num : num;
    }

public:
    int myAtoi(string s)
    {
        // 1
        int idx = skipSpace(s, 0);

        // 2
        if (idx == s.length())
        {
            return 0;
        }
        bool isNegative = (s[idx] == '-');

        idx = skipSign(s, idx);

        // 3
        string digitsStr = substrDigits(s, idx);

        // 4, 5
        long long num = atoll(digitsStr, isNegative);

        // 6
        return static_cast<int>(num);
    }
};
// @lc code=end
