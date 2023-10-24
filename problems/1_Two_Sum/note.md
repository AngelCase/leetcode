## 問題
整数の配列が与えられ、
要素同士の和が指定された値になるような
要素番号のペアを返せ。

## 解法
### 1. Brute Force
```cpp
vector<int> twoSum(vector<int> &nums, int target)
{
	for (auto i = 0; i < nums.size() - 1; ++i)
		for (auto j = i + 1; j < nums.size(); ++j)
			if (nums[i] + nums[j] == target)
				return {i, j};
	return {};
}
```
総当たり。
$O(n^2)$の解法。

### 2. Two-pass Hash Table
```cpp
vector<int> twoSum(vector<int> &nums, int target)
{
	std::unordered_map<int, int> map{};
	for (int i = 0; i < nums.size(); ++i)
	{
		map.emplace(nums[i], i);
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		int complement = target - nums[i];
		if (map.count(complement) && map.at(complement) != i)
		{
			return {i, map.at(complement)};
		}
	}

	return {};
}
```
リストを2周する。
1周目ではマップに値とそのインデックスを格納。
2週目では補数（target - nums[i]）がマップの中に存在するかを確認する。

$O(n)$の解法。

### 3. One-pass Hash Table
```cpp
vector<int> twoSum(vector<int> &nums, int target)
{
	std::unordered_map<int, int> map{};
	for (int i = 0; i < nums.size(); ++i)
	{
		int complement = target - nums[i];
		if (map.count(complement))
		{
			return {map.at(complement), i};
		}
		map.emplace(nums[i], i);
	}
	return {};
}
```
2と同じだが、リストを1周だけする。

## 学び
mapとunordered_map
