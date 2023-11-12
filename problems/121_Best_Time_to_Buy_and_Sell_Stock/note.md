## 問題
`prices[i]`が`i`日目の株式の価格であるような
配列`prices`が与えられる。

一つの日を1つの株式を買う日として選び、
未来の別の日を売る人して選んで、
あなたの利益を最大化したい。

この取引で得られる利益の最大値を返せ。
もしなんの利益も得られない場合、`0`を返せ。

## 解法
### 1. DP
```cpp
int maxProfit(vector<int> &prices)
{
	int ans = 0;
	int minPrice = prices[0];
	for (int i = 1; i < prices.size(); ++i)
	{
		ans = max(ans, prices[i] - minPrice);
		minPrice = min(minPrice, prices[i]);
	}

	return ans;
}
```
