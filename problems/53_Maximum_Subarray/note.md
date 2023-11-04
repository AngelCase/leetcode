## 問題
整数配列`nums`が与えられたとき、
総和が最大の部分配列を見つけ、その総和を返せ。

## 解法
### 1. Kadane's algorithm
```cpp
int maxSubArray(vector<int> &nums)
{
	int bestSum = -1e4;
	int curSum = 0;
	for (auto num : nums)
	{
		curSum = max(num, curSum + num);
		bestSum = max(bestSum, curSum);
	}
	return bestSum;
}
```
カダネのアルゴリズムを使う。
詳細は「学び」の項目にて。

### 2. 動的計画法
```cpp
int maxSubArray(vector<int> &nums)
{
	vector<int> dp{};
	dp.push_back(nums[0]);
	int curMax = dp[0];

	for (int i = 1; i < nums.size(); ++i)
	{
		dp.push_back(max(nums[i] + dp[i - 1], nums[i]));
		curMax = max(curMax, dp[i]);
	}

	return curMax;
}
```
カダネのアルゴリズムとほぼ同じ。
`dp[i]`には`nums[i]`までの部分配列の総和の最大値が入る。

## 学び
### Kadane's algorithm
アルゴリズムの概要は以下の通り。

配列を順に見ていき、今見ている要素までの総和をとる。
順に見ているので、総和は$(直前の総和+現在の値)$で計算できる。
```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]
現在の値：-2
総和：0（初期値）
最大の総和：-inf
↓
現在の値：-2
総和：0 + (-2) = -2
最大の総和：-2
```

もし総和よりも現在の値の方が大きければ、
これまでの総和をリセットして、現在の値からまた総和を計算し始める。
```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]
現在の値：1
総和：-2
最大の総和：-inf
↓
総和：1（現在の値の方が大きいのでリセット）
最大の総和：1
```

これを配列の最後まで繰り返し、
今までに登場した総和のうち最大のものが求めるべき解となる。

#### 参考
https://www.youtube.com/watch?v=5WZl3MMT0Eg
https://en.wikipedia.org/wiki/Maximum_subarray_problem

### 動的計画法
#### 参考
[[アルゴリズム(Ruby)]分割統治法・動的計画法（マージソート・フィボナッチ数・部分和問題を例に解説） - じゃいごテック (jaigotec.com)](https://jaigotec.com/algorithm_divide_and_conquer_dp/)
[動的計画法超入門！ Educational DP Contest の A ～ E 問題の解説と類題集 #競技プログラミング - Qiita](https://qiita.com/drken/items/dc53c683d6de8aeacf5a)
