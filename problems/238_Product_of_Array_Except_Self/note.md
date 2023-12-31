## 問題
整数配列`nums`が与えられたとき、
`nums[i]`を除く`nums`の全要素の積と等しいような
`answer[i]`の`配列`answer`を返せ。

`nums`のprefix、またはsuffixの積は32ビット整数に収まることが保証される。

あなたは$O(n)$時間で動作する、除算処理を使わないアルゴリズムを書く必要がある。

## 閃き
「ある区間の総積」を求める必要が出てきたら、
累積積の考え方を用いて高速化できないか検討する。

ただし、その際割算が必要ないことを確認しておく。
割算があると遅くなるし、かつゼロ割算を防ぐ必要が出てくるので
累積和的な考え方はそのままだと使えない。


## 解法
```cpp
vector<int> productExceptSelf(vector<int> &nums)
{
	vector<int> prefix{};
	prefix.push_back(1);
	{
		int product = 1;
		for (auto num : nums)
		{
			product *= num;
			prefix.push_back(product);
		}
	}

	vector<int> suffix{};
	suffix.push_back(1);
	{
		int product = 1;
		for (int i = nums.size() - 1; 0 <= i; --i)
		{
			product *= nums[i];
			suffix.push_back(product);
		}
	}

	vector<int> ans{};
	for (int i = 0; i < nums.size(); ++i)
	{
		int left = prefix[i];
		int right = suffix[nums.size() - i - 1];
		ans.push_back(left * right);
	}

	return ans;
}
```
累積積による解法。
左からの累積積と右からの累積積を組み合わせている。
