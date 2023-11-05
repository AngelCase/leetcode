/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict{wordList.begin(), wordList.end()};

        if (dict.find(endWord) == dict.end())
        {
            return 0;
        }

        // 最短経路を探す
        queue<string> open{};

        open.push(beginWord);

        int ans = 1;
        while (!open.empty())
        {
            int n = open.size();
            for (int i = 0; i < n; ++i)
            {
                // openから取り出す
                string cur = open.front();
                open.pop();

                // ゴールの場合終了
                if (cur == endWord)
                {
                    return ans;
                }

                // 辞書から削除
                dict.erase(cur);

                // 未巡回の1文字違いをopenに追加
                for (int j = 0; j < cur.size(); ++j)
                {
                    char c = cur[j];
                    for (int k = 0; k < 26; ++k)
                    {
                        cur[j] = 'a' + k;
                        if (dict.find(cur) != dict.end())
                        {
                            open.push(cur);
                        }
                    }
                    cur[j] = c;
                }
            }
            ++ans;
        }

        return 0;
    }
};
// @lc code=end
