## 問題
整数配列`nums`が与えられたとき、
この配列のpivot indexを計算せよ。

pivot indexとは、
そのインデックスより厳密に左にある全ての数字の合計が
厳密に右にある全ての数字の合計と等しいインデックスである。

pivot indexが配列の左端にある場合、
左の合計は`0`となる。
これは右側にも同様に適用される。

最も左にあるpivot indexを返せ。
もしそのようなインデックスが存在しなければ、`-1`を返せ。

## 解法
```cpp
int pivotIndex(vector<int> &nums)
{
	vector<int> accum{};
	accum.push_back(0);
	int sum = 0;
	for (auto num : nums)
	{
		sum += num;
		accum.push_back(sum);
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		int leftSum = accum[i];
		int rightSum = accum.back() - accum[i + 1];
		if (leftSum == rightSum)
		{
			return i;
		}
	}

	return -1;
}
```
累積和による解法。
