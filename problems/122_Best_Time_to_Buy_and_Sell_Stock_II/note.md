## 問題
`prices[i]`が`i`日目の株式の値段であるような
整数配列`prices`が与えられる。

それぞれの日に、あなたは株式を買うか売るかを決められる。
いつでも最大で1つまでの株式を保有することができる。
ただし、株式を売却したのと同じ日にすぐ株式を購入できる。

得られる最大の利益を返せ。

## 解法
### 1. メモ化1
```cpp
int maxProfit(vector<int> &prices)
{
	int ans = 0;
	int cur = prices[0];

	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[i - 1] < prices[i])
		{
			ans += prices[i] - cur;
			cur = prices[i];
			continue;
		}
		cur = prices[i];
	}

	return ans;
}
```
`1,2,10`のように単調増加のとき、
毎日買って売ってを繰り返すのと、
最初の日に買って最後の日に売るのとで利益は変わらない。

`1,4,1,4`の場合だと、
最初の日に買って最後の日に売ると、
株式を保有している間に価格が下がっているので損をしている。

つまり、価格が上がるタイミングでは常に売り、
価格が下がるタイミングでは株式を保有しないようにすれば最大利益となる。

### 2. メモ化2
```cpp
int maxProfit(vector<int> &prices)
{
	int ans = 0;

	for (int i = 1; i < prices.size(); ++i)
	{
		ans += max(prices[i] - prices[i - 1], 0);
	}

	return ans;
}
```
1をさらに短くしたもの。
利益がマイナスになったらそれをなかったことにしている。
