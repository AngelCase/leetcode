## 問題
`k`番目に大きい要素を探すクラスを設計せよ。
`KthLargest(int k, int[] nums)`はオブジェクトを整数`k`と整数のストリーム`nums`で初期化する。
`int add(int val)`は整数`val`をストリームに追加し、その時点で`k`番目に大きい要素を返す。

## 解法
```cpp
class KthLargest
{
private:
	int k;
	// 昇順の優先順位付きキュー
	priority_queue<int, vector<int>, greater<int>> que;

public:
	KthLargest(int k, vector<int> &nums)
		: k(k),
		  que(priority_queue<int, vector<int>, greater<int>>{nums.begin(), nums.end()})
	{
		for (int i = 0; k < que.size(); ++i)
		{
			que.pop();
		}
	}

	int add(int val)
	{
		que.push(val);
		if (k < que.size())
		{
			que.pop();
		}
		return que.top();
	}
};
```
昇順にソートされた優先順位付きキューを用いており、
常に取り出されるのがk番目に大きい要素となっている。

そのために、つねに大きさをkに保っているのがポイント。

優先順位付きキューの要素数をちゃんと切り詰めないと、
要素が増えてきたときにソートが遅すぎてタイムリミットを超過してしまう。

## 学び
優先順位付きキュー
