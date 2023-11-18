## 問題
`days`日以内に別の港に運ぶ必要のある荷物がベルトコンベアに積まれている。

ベルトコンベアの`i`番目の荷物は`weights[i]`の重さを持つ。
毎日、ベルトコンベアの荷物を船に積み込む（`weights`の順に）。
船の最大積載重量を超える重さは積み込めない。

全てのベルトコンベアの荷物を`days`日以内に運べるような
最小積載重量を返せ。

## 解法
```cpp
bool canShip(vector<int> &weights, int capacity, int days)
{
	int total = 0;
	int count = 1;
	for (int w : weights)
	{
		total += w;
		if (capacity < total)
		{
			count++;
			total = w;
		}
	}
	return count <= days;
};

int shipWithinDays(vector<int> &weights, int days)
{
	if (weights.size() == 1)
	{
		return weights[0];
	}

	int total = 0;
	for (int w : weights)
	{
		total += w;
	}

	// とりうる積載重量の範囲で積載可能な最小値を二分探索
	// [最大値、総和]
	int start = *max_element(weights.begin(), weights.end());
	int last = total;
	int ans = 0;
	while (start <= last)
	{
		int mid = (start + last) / 2;
		if (canShip(weights, mid, days))
		{
			ans = mid;
			last = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return ans;
}
```
この問題のキモは、
とりうるキャパシティの範囲で二分探索する点。

キャパシティの最小値は荷物の重量の最大値。
キャパシティの最大値は荷物の重量の総和。
この範囲の中で、「そのキャパシティで荷物を指定の日数で運べるか？」を確認していく。
