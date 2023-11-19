## 問題
異なる要素からなる整数配列`candidates`と整数`target`が与えられたとき、
選んだ数字の合計が`target`となるような
全てのユニークな`candidates`の組み合わせのリストを返せ。

`candidates`から無制限の回数同じ数字が選ばれることがある。
選ばれた数字の出現頻度が少なくとも1つでも異なるならば
2つの組み合わせはユニークとなる。

テストケースは、 
合計が`target`となるような
与えられた入力に対するユニークな組み合わせの数が
150より小さくなるように作られている。

## 解法
### 1. 再帰
```cpp
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
	vector<vector<int>> ans{};

	for (int i = 0; i < candidates.size(); ++i)
	{
		int num = candidates[i];
		if (target == num)
		{
			ans.push_back({num});
		}
		else if (num < target)
		{
			vector<int> tail(candidates.begin() + i, candidates.end());
			vector<vector<int>> vecs = combinationSum(tail, target - num);
			for (vector<int> &vec : vecs)
			{
				vec.insert(vec.begin(), num);
				ans.insert(ans.begin(), vec);
			}
		}
	}
	return ans;
}
```
`candidates`の各値が`target`と等しければ、条件を満たす。
`target`よりも小さければ、`target`との差にぴったり合う数字が無いか再帰で調べる。
```cpp
vector<vector<int>> vecs = combinationSum(tail, target - num);
```
その際、答えに重複するものが出ないよう、調査済みの値は調べないようにする。
```cpp
vector<int> tail(candidates.begin() + i, candidates.end());
```

### 2. バックトラッキング
```cpp
void helper(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &cur, int target, int total)
{
	if (total == target)
	{
		ans.push_back(cur);
		return;
	}
	if (candidates.empty() || target < total)
	{
		return;
	}

	// 選択肢の先頭を加えて条件を満たすか試す
	cur.push_back(candidates[0]);
	helper(ans, candidates, cur, target, total + candidates[0]);

	// 1手戻し、重複がないよう選択肢を1つ減らして次へ
	int first = candidates[0];
	candidates.erase(candidates.begin());
	cur.pop_back();
	helper(ans, candidates, cur, target, total);

	// 選択肢は元に戻す
	candidates.insert(candidates.begin(), first);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
	vector<vector<int>> ans{};
	vector<int> cur{};

	helper(ans, candidates, cur, target, 0);

	return ans;
}
```
`target`と同じ値が得られるまで`candidate`の先頭要素を加えていく。
もし`target`を超えてしまったら、1手戻し、重複が発生しないよう`candidate`の先頭を省いた状態でまた試す。
