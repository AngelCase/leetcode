## 問題
整数配列`nums1`と`nums2`が与えられたとき、
共通部分の配列を返せ。

結果の要素はユニークである必要があり、
また、その順序は問わない。

## 解法
```cpp
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
	unordered_set<int> set{};

	for (const auto num : nums1)
	{
		set.emplace(num);
	}

	unordered_set<int> ansSet{};
	for (const auto num : nums2)
	{
		if (0 < set.count(num))
		{
			ansSet.emplace(num);
		}
	}

	vector<int> ans{};
	for (auto val : ansSet)
	{
		ans.push_back(val);
	}

	return ans;
}
```
unordered_setを使う。

## 学び
unordered_setはユニークなはずなのに、
要素の有無を確かめる関数がcount()なので戸惑った。

もちろん、count()は0か1しか返さない。
おそらく、他のコンテナとの共通性を持たせるためだろう。
