## 問題
辞書`wordList`を用いた`beginWord`から`endWord`までの
transformation sequenceとは、
次のような`beginWord -> s_1 -> s_2 -> ... -> s_k`の
単語の系列である：
- 全ての隣り合う単語のペアは1文字だけ異なる。
- 全ての`1 <= i <= k`に対する`s_i`は`wordList`に含まれる。`beginWord`は`wordList`にある必要がないことに注意。
- `s_k == endWord`

`beginWord`と`endWord`の2つの単語と辞書`wordList`が与えられた時、
`beginWord`から`endWord`までの最も短いtransformation sequenceの単語数を返せ。
そのような系列がなければ`0`を返せ。

## 解法
### BFS
```cpp
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
```
個人的に、1文字違う文字列を探すところで詰まった。
今回の解法のうまいところは、1文字違いを探すところの計算量が文字列の長さぶんですんでいるところ。
`unordered_set`と、アルファベットが26文字である事をうまく利用している。

もともと、以下のような実装をしていたが、これだとTLEになる。
```cpp
// 1文字違いを探す関数
bool differByChar(string &str1, string &str2)
{
        int diff = 0;
        for (int i = 0; i < str1.length(); ++i)
        {
                if (str1[i] != str2[i])
                {
                ++diff;
                }
        }
        return diff == 1;
}
...
// 1文字違いを単語リストから検索
for (string &word : wordList)
{
        if (close.find(word) == close.end() && differByChar(word, cur.str))
        {
                open.push({word, cur.cost + 1});
        }
}
```
これだと、1文字違いを探すたびにかかる計算量は以下になる：
- `wordList`の大きさ * 文字列の長さ
そのため、`wordList`が大きいケースでTLEになっていた。

うまく`unordered_set`を使って計算量を削る事が大事。
