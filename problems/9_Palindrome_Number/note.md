## 問題
与えられた値が回文になっているかどうかを返せ。
ただし、負数は回文にはならない（-121→121-）

## 解法
### 文字列を使う
```cpp
bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}

	auto str = std::to_string(x);

	while (1 < str.length())
	{
		if (str.front() != str.back())
		{
			return false;
		}

		str.erase(0, 1);
		str.pop_back();
	}

	return true;
}
```

### 与えられた値をひっくり返して比較する
```cpp
bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}

	long long reversed = 0;
	long long xCopy = x;
	while (xCopy != 0)
	{
		reversed = reversed * 10 + xCopy % 10;
		xCopy /= 10;
	}

	return x == reversed;
}
```

## 学び
### 競プロでは基本long longを使う
intを使っているとエラーが出た。
-2^31 <= x <= 2^31 - 1という制約があったが、これはintの範囲。
