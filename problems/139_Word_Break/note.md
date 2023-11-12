## 問題
文字列`s`と辞書`wordDict`が与えられたとき、
もし辞書の1つ以上の単語でスペース区切りの系列に分割できるなら
`true`を返せ。

辞書の中の同じ単語が分割時に複数回使われうる点に注意。

## 解法
### 1. DP：先頭から
```cpp
bool wordBreak(string s, vector<string> &wordDict)
{
	unordered_set<string> us(wordDict.begin(), wordDict.end());
	vector<bool> dp(s.length() + 1, false);
	dp[0] = true;

	for (int i = 0; i < s.length(); ++i)
	{
		if (!dp[i])
		{
			continue;
		}

		for (int j = 1; i + j <= s.length(); ++j)
		{
			if (us.find(s.substr(i, j)) != us.end())
			{
				dp[i + j] = true;
			}
		}
	}

	return dp.back();
}
```
`dp[i]`は、`s`の`[0,i)`の範囲の部分文字列が辞書の単語で表せるかを記憶する。
`j`の長さで`s`を切ってみて、それが辞書にあれば`dp[i]`をtrueにする。

### 2. DP：後ろから
```cpp
bool wordBreak(string s, vector<string> &wordDict)
{
	vector<bool> dp(s.length() + 1, false);
	dp[s.length()] = true;

	for (int i = s.length() - 1; 0 <= i; --i)
	{
		for (string word : wordDict)
		{
			if (dp[i])
			{
				break;
			}
			if (i + word.length() <= s.length() && word == s.substr(i, word.length()))
			{
				dp[i] = dp[i + word.length()];
			}
		}
	}

	return dp[0];
}
```

`dp[i]`は、`s`の`[i,s.end())`の範囲の部分文字列が辞書の単語で表せるかを記憶する。

`dp[i] = dp[i + word.length()];`では、
既に確認したパターンと繋げられるかを判定している。
例えば、`abc`という文字列を作りたいとして、
`b`が2文字目に置けそうな時、
すでに後ろに`c`がマッチすることが分かっていれば`b`の配置は可能となる。
