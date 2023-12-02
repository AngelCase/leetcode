## 問題
既に昇順ソートされた1次元の整数配列`numbers`が与えられたとき、
和が特定の`target`という値になる2つの値を探せ。
これら2つの値を`numbers[index1]`と`numbers[index2]`とすると、
`1 <= index1 < index2 < numbers.length`である。

2つの値の要素番号`index1`と`index2`に1を足したものを
長さ2の整数配列`[index1, index2]`として返せ。

テストは解答が1つだけとなるように生成される。
同じ要素を2度使うことはできない。

回答は定数サイズの空間だけを使う必要がある。

## 閃き
配列の先頭と末尾からスタートする2つのポインタを使うことで、
無駄な組み合わせを計算せず効率よく走査できる。

## 解法
### 1. 2 pointers
```cpp
vector<int> twoSum(vector<int> &numbers, int target)
{
	int low = 0;
	int high = numbers.size() - 1;

	while (1)
	{
		long long sum = numbers[low] + numbers[high];
		if (sum == target)
		{
			break;
		}

		if (sum < target)
		{
			low++;
		}
		else if (target < sum)
		{
			high--;
		}
	}

	return {low + 1, high + 1};
}
```
2つのポインタ`low`と`high`を用意する。
これらはそれぞれ小さい値、大きい値をとる。

合計値がターゲットより小さければ、`low`を右に、
大きければ`high`を左に移動させる。
