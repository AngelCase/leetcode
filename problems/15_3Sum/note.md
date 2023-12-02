## 問題
整数配列が与えられたとき、
`i != j`、`i != k`、`j != k`であり
`nums[i] + nums[j] + nums[k] == 0`であるような
全ての三つ揃い`[nums[i], nums[j], nums[k]]`を返せ。

回答のセットは重複する三つ揃いを含んではならない。

## 閃き
ポイントは3つ。

3つの足し算を愚直にやると$O(n^3)$になるから、
1つの値を固定して、「2つの足し算の問題を解く問題」に落とし込むこと。

効率よく足し算するためにハッシュマップを使うこと。

うまく重複を回避すること。

## 解法
### 1. unordered_set：重複をunordered_setで防ぐ
```cpp
vector<vector<int>> threeSum(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans{};

	unordered_set<int> fixUsed{};
	for (int fix = 0; fix < nums.size(); ++fix)
	{
		// 同じ固定値は2度使わない
		if (fixUsed.count(nums[fix]))
		{
			continue;
		}
		fixUsed.emplace(nums[fix]);

		unordered_set<int> values{};
		unordered_set<int> pairUsed{};
		// 残りの配列から合計が固定した値と足して0になるペアを探す
		for (int i = fix + 1; i < nums.size(); ++i)
		{
			// 回答に使った要素は2度使わない
			if (pairUsed.count(nums[i]))
			{
				continue;
			}

			int search = -(nums[i] + nums[fix]);
			if (values.count(search))
			{
				ans.push_back({nums[fix], nums[i], search});

				pairUsed.emplace(nums[i]);
				pairUsed.emplace(search);
			}
			values.emplace(nums[i]);
		}
	}

	return ans;
}
```
効率よく計算するためにunordered_setを使い、
重複をなくすためにまずソートしており、かつ使った値を2度使わないようにしている。

足し算の計算では、1つの値を固定し、
残りのサブシーケンスから作れるペアで、3つの総和が0になるものを探す。

### 2. unordered_set：重複をインデックス移動で防ぐ
```cpp
vector<vector<int>> threeSum(vector<int> &nums)
{
	sort(nums.begin(), nums.end());

	// 最後に出現したもののインデックスを記録
	unordered_map<int, int> hashMap{};
	for (int i = 0; i < nums.size(); ++i)
	{
		hashMap[nums[i]] = i;
	}

	vector<vector<int>> ans{};
	for (int fix = 0; fix < nums.size() - 2; ++fix)
	{
		if (0 < nums[fix])
		{
			break;
		}

		for (int i = fix + 1; i < nums.size() - 1; ++i)
		{
			int required = -(nums[fix] + nums[i]);
			// 重複を防ぐために、
			// 発見した値が2個目の値より後のインデックスであることを要求する
			if (hashMap.count(required) &&
				hashMap.find(required)->second > i)
			{
				ans.push_back({nums[fix], nums[i], required});
			}
			// 重複を防ぐために、2個目の値は違う数字を使う
			// そのために2個目の値の最後のインデックスに移動、forの++iで次の値からスタートする
			i = hashMap.find(nums[i])->second;
		}
		// こちらも同様。
		// 重複を防ぐために、最後に固定値が出現したインデックスへ
		fix = hashMap.find(nums[fix])->second;
	}

	return ans;
}
```
計算の効率化は1.と同じ。

重複の防ぎ方として、
3つ組のそれぞれの位置で同じ値を二度使わないようにしている。
そのために、unordered_mapにあらかじめ
「その値の最後の出現位置」を入れておき、
次回のループでは次の新しい値から始まるようにしている。

### 3. 2 pointers
```cpp
vector<vector<int>> threeSum(vector<int> &nums)
{
	sort(nums.begin(), nums.end());

	vector<vector<int>> ans{};

	for (int i = 0; i < nums.size() - 2; ++i)
	{
		// 固定値の重複を防ぐ
		if (0 < i && nums[i] == nums[i - 1])
		{
			continue;
		}

		int low = i + 1;
		int high = nums.size() - 1;
		while (low < high)
		{
			int sum = nums[i] + nums[low] + nums[high];
			if (sum < 0)
			{
				low++;
			}
			else if (0 < sum)
			{
				high--;
			}
			else
			{
				ans.push_back({nums[i], nums[low], nums[high]});

				// lowポインタの重複を防ぐ
				int lowNum = nums[low];
				while (low < high && nums[low] == lowNum)
				{
					low++;
				}

				// highポインタの重複を防ぐ
				int highNum = nums[high];
				while (low < high && nums[high] == highNum)
				{
					high--;
				}
			}
		}
	}
	return ans;
}
```
2つのポインタ`low`と`high`を用意する。
名前の通り、それぞれ小さい値と大きい値をとる。

3つ組の合計が-veなら、`low`を大きくする。
+veなら、`hight`を小さくする。

もし合計が`0`なら、重複を避けるために
ポインタを2つとも次の値へと移動させる。

何故か直感的に漏れがありそうな感じがしたので、
やや冗長だが漏れがないことを具体例で確認する。
ケース1。
例えば`[2, 4, 7, 8]`という配列があり、`9`を作りたいとする。
まず、`2 + 8 = 10`で`9`より大きい。
この時`high`を下げる理由は、`8`を使って`9`を作れるパターンがないから。
だからこれ以上`8`を使う組み合わせを調べる必要がない。
ケース2。
ケース1の後、`2 + 7 = 9`で`9`を作れる。
この後、次の解を探す際両方のポインタを移動させる。
`8`だけでなく`2`も移動させるのは、
既に`2`で正解の組み合わせを見つけたら
`2`を使った他の組み合わせは絶対にないから。

