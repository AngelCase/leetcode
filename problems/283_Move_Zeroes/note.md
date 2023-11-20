## 問題
整数配列`nums`が与えられたとき、
すべての非ゼロ要素の順序を保ちながら、
`0`を末尾に移動せよ。

配列のコピーを作らずにその場で実行する必要があることに注意。

## 閃き
不要。
問題文の通りに実装すればよい。

## 解法
### 1. 0を後ろに移動させる
```cpp
void moveZeroes(vector<int> &nums)
{
	auto itr = nums.begin();
	int count = 0;
	while (itr != nums.end())
	{
		if (*itr == 0)
		{
			itr = nums.erase(itr);
			++count;
		}
		else
		{
			++itr;
		}
	}

	for (int i = 0; i < count; ++i)
	{
		nums.push_back(0);
	}
}
```
`0`を見つけたら削除し、消した分を後から後ろに付け加える。
イテレータでループしているので、その扱いにさえ気を付ければ難しくない。

### 2. 非ゼロ要素を先頭に移動させる
```cpp
void moveZeroes(vector<int> &nums)
{
	int insertPos = 0;
	for (int num : nums)
	{
		if (num != 0)
		{
			nums[insertPos] = num;
			insertPos++;
		}
	}

	while (insertPos < nums.size())
	{
		nums[insertPos] = 0;
		insertPos++;
	}
}
```
非ゼロ要素を見つけたら、先頭に上書きしていく。
一通り見終わったら、上書きしなかった部分を`0`で上書きしていく。
