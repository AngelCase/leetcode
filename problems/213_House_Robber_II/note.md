## 問題
あなたは通り沿いの家を強盗しようとしているプロの強盗である。
それぞれの家はある金額のお金を隠している。
ここの全ての家は円形に配置されている。
つまり、最初の家は最後の家の隣にある。
一方、隣接する家は連結したセキュリティシステムを持っており、
2つの隣接する家が同じ夜に侵入された場合、自動的に警察に連絡される。

それぞれの家のお金の金額を示す整数配列`nums`が与えられたとき、
警察に通報されることなく今夜強盗できる金額の合計を返せ。

## 解法
### 1. 2重DP
```cpp
int calcMax(vector<int> &&nums)
{
	int prev1 = 0;
	int prev2 = 0;

	for (int num : nums)
	{
		int tmp = prev1;
		prev1 = max(prev2 + num, prev1);
		prev2 = tmp;
	}

	return prev1;
}

int rob(vector<int> &nums)
{
	if (nums.size() == 1)
	{
		return nums[0];
	}

	int max1 = calcMax(vector<int>(nums.begin(), nums.end() - 1));
	int max2 = calcMax(vector<int>(nums.begin() + 1, nums.end()));
	return max(max1, max2);
}
```
最後の要素を含まない部分配列での最大と、
最初の要素を含まない部分配列での最大を比較する。
そうすれば、先頭要素と最後の要素が同時に含まれない最大値が得られる。

また、`prev1`と`prev2`の初期値を0にしているのもポイント。
こうすることで境界値を気にすることなくループを回せる。

## 学び
DPでは、範囲外の要素を適切に初期化しておくと
境界値のコントロールが楽になる。
