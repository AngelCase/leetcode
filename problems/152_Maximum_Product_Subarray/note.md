## 問題
整数配列`nums`が与えられたとき、
最大の総積をとる部分配列を見つけ、
その積を返せ。

テストケースは回答が32-bit整数に解答が収まるように
作られている。

## 閃き
マイナス同士を掛けると最大値となりうるので、
部分配列の最大値だけでなく最小値も記録しておくのが重要。

また、掛け算や割り算をするとき、
エッジケースの`0`をどう扱うかは意識する。

## 解法
### 1. 
```cpp
int maxProduct(vector<int> &nums)
{
	long long ans = *max_element(nums.begin(), nums.end());

	long long curMax = 1;
	long long curMin = 1;
	for (long long num : nums)
	{
		int tmp = curMax;
		curMax = max(num, max(num * curMin, num * curMax));
		curMin = min(num, min(num * curMin, num * tmp));

		ans = max(ans, curMax);
	}

	return ans;
}
```
部分配列を大きくしていきながら、
積の最大値と最小値を計算していく。

最小値を持つのがミソ。
最小値は、マイナス同士の掛け算で巨大なプラスの値になる可能性を持っているため。
