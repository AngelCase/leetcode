## 問題
互いに異なる整数の配列`nums`が与えられたとき、
可能な順列を全て返せ。
回答は自由な順序で返してよい。

## 制約
`nums`の全ての整数はユニークである。

## 解法
### 1. next_permutation
```cpp
vector<vector<int>> permute(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans{};

	do
	{
		ans.push_back(nums);
	} while (next_permutation(nums.begin(), nums.end()));

	return ans;
}
```
`std::next_permutation`を用いた解法。

### 2. バックトラッキング
```cpp
vector<vector<int>> permute(vector<int> &nums)
{
	if (nums.size() == 1)
	{
		return vector<vector<int>>{nums};
	}

	vector<vector<int>> ans{};

	for (int i = 0; i < nums.size(); ++i)
	{
		int num = nums[i];
		nums.erase(nums.begin() + i);

		for (vector<int> &vec : permute(nums))
		{
			vec.insert(vec.begin(), num);
			ans.push_back(vec);
		}

		nums.insert(nums.begin() + i, num);
	}

	return ans;
}
```
配列から1つ要素を取り上げ、それを残りの配列の各順列の先頭にくっつけた配列を返す。
例えば`[1,2,3]`から`1`を取り上げ、`[2,3]`の各順列の頭にくっつけると考える。
つまり、パターンは以下である：
- `[1] + [2,3]`
- `[1] + [3,2]`

次に、`[2,3]`の順列を作る方法だが、これも同様である。
`2`を取り上げて先頭にくっつけると`[2,3]`ができる。
`3`を取り上げて先頭にくっつけると`[3,2]`ができる。

## 学び
### なにも思いつかなかったらとりあえず木にしてみる
今回の場合、以下のような木を作れたら思いつくかも。
- 123
  - 1,23
    - 1,2,3
    - 1,3,2
  - 2,13
    - 2,1,3
    - 2,3,1
  - 3,12
    - 3,1,2
    - 3,2,1

### next_permutation
辞書順の次の配列を返す。
対象の配列はあらかじめ昇順ソートしておく必要がある。
