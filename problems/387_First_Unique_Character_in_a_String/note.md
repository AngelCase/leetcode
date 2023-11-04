## 問題
文字列`s`が与えられたとき、最初の繰り返さない文字の要素番号を返せ。
もし存在しなければ-1を返せ。

## 解法
### 1. 最初の出現位置と最後の出現位置の比較
```cpp
int firstUniqChar(string s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		char c = s.at(i);
		if (s.find(c) ==
			s.find_last_of(c))
		{
			return i;
		}
	}

	return -1;
}
```
最初の出現位置と最後の出現位置が同じなら、
その文字はユニークと判定する。

### 2. mapを使う
```cpp
int firstUniqChar(string s)
{
	unordered_map<char, int> um{};
	for (char c : s)
	{
		um[c]++;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		if (um.at(s.at(i)) == 1)
		{
			return i;
		}
	}

	return -1;
}
```
