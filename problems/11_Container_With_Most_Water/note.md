## 問題
長さ`n`の整数配列`height`が与えられる。
`i`番目の線の2つの両端が`(i, 0)`と`(i, height[i])`であるような
`n`個の垂直な線が描かれている。

コンテナに最も多くの水が含まれるように、
x軸とともにコンテナを形成する2つの線を探せ。

コンテナに入れられる水量の最大値を返せ。

コンテナを傾けることはできない。

## 閃き
主に2つ。
まずは2つのポインタを使うこと。
次に、低い方のポインタだけを動かすこと。

## 解法
### （時間切れ）総当たり
```cpp
int maxArea(vector<int> &height)
{
	int ans = 0;
	for (int l = 0; l < height.size() - 1; ++l)
	{
		for (int r = l + 1; r < height.size(); ++r)
		{
			int lowerHeight = min(height[l], height[r]);
			ans = max(ans, lowerHeight * (r - l));
		}
	}

	return ans;
}
```

### 1. 2 pointers
```cpp
int maxArea(vector<int> &height)
{
	int l = 0;
	int r = height.size() - 1;
	int ans = 0;

	while (l < r)
	{
		int lowerHeight = min(height[l], height[r]);
		ans = max(ans, lowerHeight * (r - l));

		if (height[l] < height[r])
		{
			l++;
		}
		else
		{
			r--;
		}
	}

	return ans;
}
```
左端と右端から始まる2つのポインターを用意し、
高さが低い方を動かす。

各ステップではそれぞれのポインターが指すところを両端とするようなコンテナの容量を計算し、
ポインタがぶつかるまで繰り返して最大値を探す。

全ての組み合わせを調べないことによって計算量を減らしている（総当たりの$O(n^2)$から$O(n)$）。
低い方を動かす、という考え方は
「現在の容量は低い方の線にとって最大値である」ということに気づけば納得できる。
逆に言うと、高い方を動かしても容量は絶対に大きくならない。
例えば、両端の値がそれぞれ1と5だったとして、5を動かしても高さは1が最大だから、
幅だけが狭くなる以上値が大きくなるはずがない。
