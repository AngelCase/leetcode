## 問題
他とは異なる値からなる、昇順ソートされた整数配列`nums`がある。

あなたの関数に渡される前に、
`nums`は不明なピボットインデックス`k(1 <= k < nums.length)`で
回転される可能性があり、
その結果の配列は0始まりのインデックスで
`[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`のようになります。
例えば、`[0,1,2,4,5,6,7]`がピボットインデックス`3`で回転された場合
`[4,5,6,7,0,1,2]`のようになります。

回転された可能性のある配列`nums`と整数`target`が与えられたとき、
`nums`の中にあれば`target`のインデックスを、
`nums`の中に無ければ`-1`を返せ。

アルゴリズムは$O(log_n)$の実行時間複雑性で書く必要がある。

## 解法
### 1. 二分探索：
```cpp
int search(vector<int> &nums, int target)
{
	int start = 0;
	int last = nums.size() - 1;

	int ans = -1;
	while (start <= last)
	{
		int mid = (start + last) / 2;
		if (nums[mid] == target)
		{
			ans = mid;
			break;
		}

		if (start == last)
		{
			break;
		}

		// 右側にある
		// ・中央→右で増加かつその間の値
		// ・中央→右で減少かつ左と中央の間にない
		if ((nums[mid] < nums[last] && nums[mid] < target && target <= nums[last]) ||
			(nums[last] < nums[mid] && (target < nums[start] || nums[mid] < target)))
		{
			start = mid + 1;
		}
		// 左側にある
		else
		{
			last = mid - 1;
		}
	}

	return ans;
}
```
中央の値をまずとり、それと一致するかを確認。
一致しなければ、左と右のどちらにあるのかを探す。

左右どっちにあるかを探すのがキモ。
左と中央、中央と右の2区間のうち、単調増加している区間を探す（つまりピボットがない区間）。
単調増加している区間であれば、その左端と右端の範囲の値か？を容易に調べられる。
