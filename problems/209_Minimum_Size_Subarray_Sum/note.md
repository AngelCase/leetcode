## 問題
正の整数配列`nums`と正の整数`target`が与えられたとき、
総和が`target`以上となる最も短い部分配列の長さを返せ。
もしそのような部分配列が無ければ`0`を返せ。

## 解法
### 1. （未最適化）累積和とsliding window
```cpp
int minSubArrayLen(int target, vector<int> &nums)
{
	vector<int> accum(nums.size() + 1);
	accum[0] = 0;
	for (int i = 1; i <= nums.size(); ++i)
	{
		accum[i] = accum[i - 1] + nums[i - 1];
	}

	int minLen = INT_MAX;
	int left = 0;
	int right = 1;
	while (right <= nums.size())
	{
		int sum = accum[right] - accum[left];
		if (target == sum)
		{
			minLen = min(minLen, right - left);
			left += 2;
			right = left + 1;
		}
		else if (target < sum)
		{
			minLen = min(minLen, right - left);
			left++;
			right--;
			if (right <= left)
			{
				right = left + 1;
			}
		}
		else
		{
			right++;
		}
	}
	return (minLen == INT_MAX) ? 0 : minLen;
}
```
総和を計算することになるから、という理由で累積和を導入したが
sliding windowで必要にならないケースまで計算してしまっているため余計遅くなってしまった。

### 2. sliding window
```cpp
int minSubArrayLen(int target, vector<int> &nums)
{
	int minLen = INT_MAX;
	int left = 0;
	int right = 0;
	int sum = 0;
	while (right < nums.size())
	{
		sum += nums[right];
		right++;
		while (target <= sum)
		{
			minLen = min(minLen, right - left);
			sum -= nums[left];
			left++;
		}
	}
	return (minLen == INT_MAX) ? 0 : minLen;
}
```
`while`ループが2重になっていて、
外側では`right`を右に移動、
内側では条件を満たす限り`left`を左に移動させている。

## 学び
for文でイテレーションされている変数をループ内でも動かすと混乱するので
そのようなやり方は避ける。
例えば、以下のようなやり方はバグのもと。
```cpp
for(int i = 0; i < n; i++){
	if (cond) {
		i += 2;
	}
}
```
