## 問題
整数配列`nums`が与えられたとき、
厳密に増加する部分系列の長さを返せ。

部分系列とは、
別の配列から0個以上の要素を削除して
残りの要素の順序を変えることなく
得られる配列である。

## 解法
### 1. DP
```cpp
int lengthOfLIS(vector<int> &nums)
{
	int size = nums.size();
	vector<int> dp(size, 1);

	int ans = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	return ans;
}
```
先頭から部分配列ごとに最長の長さを配列`dp`にメモしていく。
部分系列の末尾と現在の値を比較することで、
現在見ているところまでの最長の長さが以下のように計算できる：
```
max(1, dp[i - 1] + 1, dp[i - 2] + 1, ..., dp[0] + 1)
```

なお、なぜ末尾の値と比較すればいいのかというと、
最長をメモしたときの系列には必ず末尾の値が含まれるからである。

## 学び
### 一様初期化
コンストラクタの呼び出しを波括弧`{}`で記述する構文。

#### 注意すべき仕様
`std::initializer_list`型を取るコンストラクタと
初期化子リストの要素型と同じ型のパラメータリストを受け取るコンストラクタがあった時、
`std::initializer_list`型を受け取るコンストラクタが優先して呼び出される。
```cpp
struct X {
  X(std::initializer_list<double>) {
    std::cout << 1 << std::endl;
  }
  X(double d) {
    std::cout << 2 << std::endl;
  }
};

X x1 = {3.0}; // 「1」が出力される
```
非`std::initializer_list`のコンストラクタを呼び出す場合、
丸括弧でのコンストラクタ呼び出しが必要。

#### 危険なケースの例
`std::vector`には要素数と初期化時の値を取るコンストラクタがあるが、
`std::initializer_list`を取るコンストラクタもあるため注意。
```cpp
vector<int> arr1(1, 2);    // [2]
vector<int> arr2{1, 2};    // [1,2]
vector<int> arr3 = {1, 2}; // [1,2]
```

#### 参考
[一様初期化 - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/lang/cpp11/uniform_initialization.html)
[C++11 Universal Initialization は、いつでも使うべきなのか #C++ - Qiita](https://qiita.com/h2suzuki/items/d033679afde821d04af8)

