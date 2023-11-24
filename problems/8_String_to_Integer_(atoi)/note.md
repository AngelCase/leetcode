## 問題
文字列を32-bit符号好き整数に変換する`myAtoi(string s)`関数を実装せよ
（C/C++の`atoi`関数に似ている）。

`myAtoi(string s)`のアルゴリズムは以下の通り。

1. 内容を読み、最初の空白は無視する。
2. 次の文字が`-`か`+`であるかを確認する（もしすでに文字列の最後にいなければ）。どちらかであればこの文字を読む。これはそれぞれ結果がマイナスかプラスかを決める。どちらも存在しなければ結果はプラスと仮定する。
3. 数字でない文字か入力末尾に到達するまで、次の文字を読む。残りの文字列は無視される。
4. これらの数字を整数に変換する（つまり、`"123" → 123`、`"0032" → 32`）。もし1つの数字も読まれなかったら、整数は`0`。必要に応じて符号は変える（ステップ2より）。
5. もし整数が32-bit符号付き整数の範囲`[-2^31, 2^31-1]`の外にある場合、範囲内に収まるように整数をクランプする。具体的には、`-2^31`より小さい整数は`-2^31`にクランプされ、`2^31-1`より大きい整数は`2^31-1`にクランプされる。
6. 整数を最終的な結果として返す。

注意：
空白文字`' '`だけが空白として扱われる。
先頭の空白以外と数字の後の文字列以外、どの文字列も無視してはならない。

## 閃き
不要。
それぞれのステップで、
「コンテナの範囲外へのアクセス」や「桁あふれ」などの
エラーが起きないように意識することが重要。

## 解法
### 1. 
```cpp
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
```
アルゴリズムやデータ構造の知識問題ではなく、
シンプルに実装するだけの問題だと感じたので
機能ごとのテストがしやすくなるように設計した。

`[INT_MIN,INT_MAX]`へのクランプは、
計算中のメモを`long long`で扱うことで桁あふれが発生しないようにしている。

1文字の数字を整数に変換する処理は
文字`'0'`との差をとることで実現している。

ただの感想だが、普段の数学的なクイズより
こっちの「実現したいことを分割して実装していく」方が楽しい。
