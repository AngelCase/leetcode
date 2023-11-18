## 問題
文字列`s`が与えられたとき、繰り返しの文字がない最長の部分文字列を返せ。

## 解法
### 1. sliding window
```cpp
int lengthOfLongestSubstring(string s)
{
	if (s.empty())
	{
		return 0;
	}
	int start = 0;
	int len = 0;

	while (start + len < s.length())
	{
		len++;
		string substr = s.substr(start, len);

		for (char c : substr)
		{
			if (substr.find_first_of(c) != substr.find_last_of(c))
			{
				start++;
				len--;
				break;
			}
		}
	}

	return len;
}
```
sliding windowで、窓の中が条件を満たしているかを確認し、
条件を満たさなければ窓の幅はそのまま、右にずらしていく。

### 2. hash map
```cpp
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
```
過去に出現した文字をhash setに格納し、
今見ている文字と同じものが既に出現していたら、
過去出現したところの次から再度スタートする。
`abca`のような場合、2度目の`a`に着いたら`b`から最長を探す。

現在見ている範囲外の文字を、二度出現したと誤検知しないよう注意。
`um[s[right]] < left`の箇所でそれを防いでいる。
