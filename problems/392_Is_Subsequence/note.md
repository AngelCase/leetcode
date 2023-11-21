## 問題
2つの文字列`s`と`t`が与えられたとき、
`s`が`t`のsubsequenceであるなら`true`を返し、
そうでなければ`false`を返せ。

文字列のsubsequenceとは、
もとの文字列から残りの相対位置を乱すことなく、
いくつか文字削除、あるいはせずに作られる新しい文字列である。
例えば、`ace`は`abcde`のsubsequenceであり、
`aec`はsubsequenceではない。

## 閃き
それぞれの文字列を頭から順番に見ていけばよい。

## 解法
### 1. two pointer
```cpp
bool isSubsequence(string s, string t)
{
	int idx = 0;
	for (char c : s)
	{
		bool isMatched = false;
		while (idx < t.length())
		{
			if (c == t[idx])
			{
				isMatched = true;
				idx++;
				break;
			}
			idx++;
		}

		if (!isMatched)
		{
			return false;
		}
	}
	return true;
}
```
`s`を1文字ずつ見ていき、
それと同じ文字が出現するかを`t`も1文字ずつ見ていく。

それぞれのループの終了条件に注意。
内側のループは、
同じ文字を見つけたら成功でループ終了、
見つけられなかったら失敗でループ終了と
2つの終了ケースがある。
