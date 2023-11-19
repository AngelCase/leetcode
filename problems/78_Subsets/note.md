## 問題
ユニークな要素を持つ整数配列`nums`が与えられたとき、
可能なサブセット（べき集合）を全て返せ。

配列のサブセットとは、配列の要素を選択したものである。
要素がない場合もある。

回答は重複するサブセットを返してはならない。
回答は自由な順序で返してよい。

## 解法
### 1. 二進数による網羅
```cpp
vector<vector<int>> subsets(vector<int> &nums)
{
	int bitMax = pow(2, nums.size()) - 1;
	vector<vector<int>> ans{};

	for (int i = 0; i <= bitMax; ++i)
	{
		vector<int> vec{};
		int curBits = i;
		for (int digit = 0; digit < nums.size(); ++digit)
		{
			if (curBits & static_cast<int>(pow(2, digit)))
			{
				vec.push_back(nums[digit]);
			}
		}

		ans.push_back(vec);
	}

	return ans;
}
```
二進数で管理する。
例えば、`[1,2,3]`のような配列に対してサブセットを返す場合、
`111`のような3桁の二進数を用意する。
各桁は「その桁の値を使うか？」を表し、
`101`だと、1桁目は使う（`1`）、2桁目は使わない（`0`）、3桁目は使う(`1`)ので
`[1,3]`というサブセットが得られる。

これを、`000`から`111`まで繰り返す。

### 2. 再帰
```cpp
vector<vector<int>> subsets(vector<int> &nums)
{
	if (nums.size() == 1)
	{
		return vector<vector<int>>{{}, nums};
	}

	vector<vector<int>> ans{};

	int head = nums[0];
	nums.erase(nums.begin());
	for (vector<int> vec : subsets(nums))
	{
		ans.push_back(vec);
		vec.insert(vec.begin(), head);
		ans.push_back(vec);
	}

	return ans;
}
```
まず配列の先頭要素を取り除いたときのサブセットを列挙し、
それに対して、先頭要素を戻す/戻さないというそれぞれのパターンを列挙したものが答え。

例えば、`[1,2,3]`に対して、先頭要素`1`を省くと`[2,3]`。
`[2,3]`のサブセットは`[[], [2], [3], [2,3]]`であり、
これらすべてに`1`を戻す/戻さないというパターンを列挙すればよい。
サブセットの要素の1つ`[2]`の場合、`[1,2]`と`[2]`というパターンができる。

`[2,3]`のサブセットを列挙する際も、
同様に先頭の`2`を省いて残りの`[3]`のサブセットを列挙する、という所からスタートできる。

`[3]`のサブセットは空`[]`かそのまま`[3]`だけなので簡単に列挙できる。

### 3. 反復
```cpp
vector<vector<int>> subsets(vector<int> &nums)
{
	vector<vector<int>> sets{{}};

	for (int num : nums)
	{
		int setSize = sets.size();
		for (int i = 0; i < setSize; ++i)
		{
			vector<int> set = sets[i];
			set.push_back(num);
			sets.push_back(set);
		}
	}

	return sets;
}
```
反復的な解法。
サブセットには空の配列を与えておき、
それに対して`nums`の各要素を加えたものをサブセットに追加していく。

注意点は、内側のループのループ回数をちゃんと管理すること。
`for (auto set : sets)`のようにしてしまうと、
内部で要素を増やしているのでループがおかしくなる。

## 学び
### 範囲ベースforの中でコンテナの要素数を変える場合、最新の注意を払う
