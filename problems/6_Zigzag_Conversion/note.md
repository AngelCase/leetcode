## 問題
文字列`PAYPALISHIRING`は
次のような行数で与えられたジグザグパターンで書かれている：
```
P A H N
APLSIIG
Y I R
```

次に、1行ずつ読むと：`"PAHNAPLSIIGYIR"`

文字列を受け取り、与えられた行数に対して
この変換を行うコードを書け。

## 閃き
不要だが、エッジケースでどういう挙動なのかの確認が必要。
たとえば行数が2の時どうなるかが
問題文だけだと不明。

## 解法
### 1.
```cpp
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
```
ネストが深すぎるので、
上昇時・下降時で関数を分けてもいいかも。
