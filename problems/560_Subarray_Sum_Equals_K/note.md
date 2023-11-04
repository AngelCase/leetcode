## 問題
整数配列`nums`と整数`k`が与えられたとき、
合計が`k`の部分配列の数を返せ。

部分配列は空でない連続した配列中の要素の系列である。

## 解法
### 1. 総当たり（TLE）
総当たりをするとTLEになる。
```cpp
int subarraySum(vector<int> &nums, int k)
{
	int ans = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; i + j < nums.size(); ++j)
		{
			vector<int> sub{nums.begin() + i, nums.begin() + i + j + 1};
			int sum = 0;
			for (auto val : sub)
			{
				sum += val;
			}

			if (sum == k)
			{
				ans++;
			}
		}
	}

	return ans;
}
```

### 2. 累積和
```cpp
int subarraySum(vector<int> &nums, int k)
{
	unordered_map<int, int> um{};
	um[0] = 1;
	int sum = 0;
	int ans = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums.at(i);
		if (um.find(sum - k) != um.end())
		{
			ans += um.at(sum - k);
		}
		um[sum]++;
	}

	return ans;
}
```
unordered_mapは、
累積和をキーにとり、バリューにその累積和となるパターンの数を持つ。

累積和同士の引き算で区間の総和を出せることを利用し、
累積和同士の差がkとなる組み合わせがいくつあるかを計算する。

## 学び
### 累積和
配列$a_0,a_1,a_2,...,a_{N-1}$に対して
配列$s_0,s_1,s_2,...,s_{N-1},s_N$を以下のように定めたもの。
- $s_0 = 0$
- $s_1 = a_0$
- $s_2 = a_0 + a_1$
- $s_3 = a_0 + a_1 + a_2$
- ...
- $s_N = a_0 + a_1 + a_2 + ... + a_{N-1}$

例えば、$a = {3,6,8,2}$であれば$s={0,3,9,17,19}$である。

これを用いると、例えば配列$a$の区間$[3,7)$の総和を以下で求められる：
$s_7-s_7$
