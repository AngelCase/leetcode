## 問題
整数配列`nums`と整数`k`が与えられたとき、
最も多く出現する要素を`k`個返せ。
返す配列の順序は問わない。

## 解法
### 1. 優先度付きキューを使う
```cpp
vector<int> topKFrequent(vector<int> &nums, int k)
{
	// 出現頻度を数える
	// 値、出現回数
	unordered_map<int, int> map{};
	for (const auto num : nums)
	{
		++map[num];
	}

	// 頻度が高いものからk個返す
	// [出現回数、値]
	auto less = [](auto &a, auto &b)
	{ return a.first < b.first; };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(less)> que{less};

	for (auto itr = map.begin(); itr != map.end(); ++itr)
	{
		que.push(pair<int, int>{itr->second, itr->first});
	}

	vector<int> answer{};
	for (int i = 0; i < k; ++i)
	{
		answer.push_back(que.top().second);
		que.pop();
	}

	return answer;
}
```
優先度付きキューを使っている部分で$O(n logn)$に近い計算量になっている。

### 2. nth_elementを使う
```cpp
vector<int> topKFrequent(vector<int> &nums, int k)
{
	// 出現頻度を数える
	// 値、出現回数
	unordered_map<int, int> map{};
	for (auto num : nums)
	{
		++map[num];
	}

	vector<pair<int, int>> v{map.begin(), map.end()};
	nth_element(v.begin(), v.begin() + k, v.end(), [](auto &a, auto &b)
				{ return b.second < a.second; });

	vector<int> answer{};
	for (int i = 0; i < k; ++i)
	{
		answer.push_back(v.at(i).first);
	}

	return answer;
}
```
nth_elementの計算量は平均で線形時間（$O(N)$）。
全体でも$O(N)$の計算量となる。

## 学び
### priority_queueに独自の比較関数を渡す方法
比較関数にラムダ式を渡すこともできる。
```cpp
auto compare = [](int a, int b) {
  return a < b;
};

std::priority_queue<
  int,
  std::vector<int>,
  decltype(compare) // 比較関数オブジェクトを指定
> que {compare};

que.push(3);
que.push(1);
que.push(4);

while (!que.empty()) {
  std::cout << que.top() << std::endl;
  que.pop();
}
```
出力：
```
4
3
1
```
比較関数では`true`になるときに第一引数`a`の優先度が下がる。
今回は「最大のものを取り出す」という条件にしたいので、
第一引数`a`が小さいとき`true`にしている。

`decltype`はオペランドで指定した式の型を取得する機能。
テンプレートにラムダ式の型を渡すために使っている。

また、コンストラクタは引数に比較関数をとっている。

#### 参考
[priority_queue - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/reference/queue/priority_queue.html)
[decltype - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/lang/cpp11/decltype.html)

### nth_element
基準要素より小さい要素が前に来るように並び替える。
それによって以下のような状態となる：
- 基準位置`nth`をソートしたときの位置に持ってくる
- 基準位置より前にはそれより小さい要素だけがある
- 基準位置より前にはそれより大きい要素だけがある
- ただし、ソートは行われない

#### 例
以下のプログラムでは0から数えて3番目の要素だけ、ソート後の要素になっている。
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> v = {5, 10, 4, 7, 1, 9, 8, 6, 2};

  // 4番目に小さい値より小さい値を前に集める
  std::nth_element(v.begin(), v.begin() + 3, v.end());

  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << std::endl;
  });
}
```
出力：
```
2
1
4
5
10
9
8
6
7
```
今回3番目の要素は`5`。
`[0,3)`の要素は`5`よりも小さく、
`(3,last)`の要素は`5`よりも大きくなっている。

#### 参考
[nth_element - cpprefjp C++日本語リファレンス](https://cpprefjp.github.io/reference/algorithm/nth_element.html)


