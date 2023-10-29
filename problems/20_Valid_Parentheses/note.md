## 問題
以下の6種類の文字を含む文字列があったとき、それが有効かを判定せよ。
- (
- )
- {
- }
- [
- ]

有効である条件は以下。
1. 開くブラケットは同じ種類のブラケットで閉じられている。
2. 開くブラケットは正しい順序で閉じられている。
3. 全ての閉じるブラケットは対応する同じ種類のブラケットで開かれている。

## 解法
```cpp
bool isValid(std::string s)
{
	std::stack<char> waits{};
	while (!s.empty())
	{
		char c = s.at(0);
		if (c == '(')
		{
			waits.push(')');
		}
		else if (c == '{')
		{
			waits.push('}');
		}
		else if (c == '[')
		{
			waits.push(']');
		}
		else if ((c == ')' ||
					c == '}' ||
					c == ']') &&
					(!waits.empty() && c == waits.top()))
		{
			waits.pop();
		}
		else
		{
			return false;
		}

		s.erase(0, 1);
	}

	if (!waits.empty())
	{
		return false;
	}

	return true;
}
```

## 学び
