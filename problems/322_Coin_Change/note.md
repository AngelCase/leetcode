## 問題
異なる種類のコインを表す整数配列`coins`と
お金の合計金額を表す整数`amount`が与えられる。

その金額を作るために必要な最も少ないコインの数を返せ。
どのコインの組み合わせでもその金額が作れない場合、
`-1`を返せ。

それぞれのコインは無限にあると想定してよい。

## 解法
### 1. DP：足す
```cpp
int coinChange(vector<int> &coins, int amount)
{
	vector<int> dp(amount + 1, -1);
	dp[0] = 0;

	for (int i = 0; i < amount; ++i)
	{
		if (dp[i] == -1)
		{
			continue;
		}
		for (long long coin : coins)
		{
			long long sum = i + coin;
			if (sum <= amount)
			{
				dp[sum] = dp[sum] == -1 ? dp[i] + 1 : min(dp[sum], dp[i] + 1);
			}
		}
	}

	return dp.back();
}
```
`dp[i]`には、金額`i`を作るための最小コイン数が入る。
そして、その金額を作れない場合の`-1`を初期値としている。

処理の概要としては、
もし`dp[i] != -1`なら、そこにコインを1枚足してみる、ということを目標金額まで繰り返し、
`amount`が作れるのかを検証している。

`int`の最大値を取りうる中で足し算をするため、`long long`を使っている。

### 2. DP：引く
```cpp
class Solution
{
public:
int coinChange(vector<int> &coins, int amount)
{
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	sort(coins.begin(), coins.end());

	for (int i = 1; i <= amount; ++i)
	{
		for (int coin : coins)
		{
			if (i - coin < 0)
			{
				break;
			}

			if (dp[i - coin] != INT_MAX)
			{
				dp[i] = min(dp[i - coin] + 1, dp[i]);
			}
		}
	}

	return dp.back() == INT_MAX ? -1 : dp.back();
}
};
```
`dp[i]`に金額`i`を作るための最小コイン数が入れているのは1と同じ。
ただし、`min()`をそのまま使えるように、初期値を`INT_MAX`にしている。

処理の概要としては、
もし`dp[i - coin] != -1`なら、そこにコインを1枚足す、ということを繰り返し
`amount`が作れるのかを検証している。
