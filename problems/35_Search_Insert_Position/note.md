## 問題
他とは異なる整数による昇順ソートされた配列とターゲットの値が与えられたとき、
ターゲットが見つかるインデックスを返せ。
もし見つからなければ、
順序に合わせて挿入した場合に見つかるべきインデックスを返せ。

アルゴリズムは$O(log_n)$の実行時間複雑性で書く必要がある。

## 解法
### 1. 二分探索
```cpp
int searchInsert(vector<int> &nums, int target)
{
	int start = 0;
	int last = nums.size() - 1;

	while (1)
	{
		int mid = (start + last) / 2;
		if (target == nums[mid])
		{
			return mid;
		}
		if (target < nums[mid])
		{
			if (mid == start)
			{
				return start;
			}
			last = mid - 1;
			continue;
		}
		if (mid == last)
		{
			return last + 1;
		}
		start = mid + 1;
	}

	return 0;
}
```
配列はソートされているので、配列の中心をとって
「イコールか？それより大きいか？それより小さいか？」を判定。
イコールでなければ、配列を半分に切って同じことを繰り返す。
