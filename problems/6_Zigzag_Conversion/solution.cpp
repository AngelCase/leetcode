/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        vector<string> lines(numRows);

        int count = 0;
        bool down = true;
        for (char c : s)
        {
            lines[count] += c;
            if (down)
            {
                // 下降、行数ぶん
                count++;
                if (count == numRows)
                {
                    // 2行の場合上昇しない
                    if (numRows == 2)
                    {
                        count = 0;
                    }
                    else
                    {
                        down = false;
                        count = numRows - 2;
                    }
                }
            }
            else
            {
                // 上昇、行数-2ぶん
                count--;
                if (count == 0)
                {
                    down = true;
                }
            }
        }

        // 配列を順によむ
        string ans = "";
        for (string &s : lines)
        {
            ans += s;
        }

        return ans;
    }
};
// @lc code=end
