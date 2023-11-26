## 問題
整数配列`nums`が与えられたとき、
いずれかの値が少なくとも配列中に2解出現したら`true`を、
全ての要素が他と違うなら`false`を返せ。

## 閃き
配列中の要素を2重のループで確認したくなったら、
まずハッシュセットでそれを1重にできないか検討する。

## 解法
### 1. unordered_set
```cpp
bool containsDuplicate(vector<int> &nums)
{
	unordered_set<int> us{};
	for (int num : nums)
	{
		if (us.find(num) != us.end())
		{
			return true;
		}
		us.emplace(num);
	}

	return false;
}
```
出てきた値をunordered_setに入れておくことで、
高速（$O(N)$）に要素の有無を確認できる。
