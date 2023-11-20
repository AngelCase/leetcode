## 問題
`n`ペアの括弧が与えられたとき、
全ての整った形の括弧の組み合わせを生成する関数を書け。

## 閃き
一文字ずつ所望の文字列を作っていくような木を考える。
各ノードにおける選択肢は、`(`か`)`を追加する、というシンプルな選択肢になる。

## 解法
### 1. BFS
```cpp
pair<int, int> countOpenClose(string str)
{
	int nOpen = 0;
	int nClose = 0;
	for (char c : str)
	{
		if (c == '(')
			nOpen++;
		else
			nClose++;
	}

	return {nOpen, nClose};
}

vector<string> generateParenthesis(int n)
{
	queue<string> que{};
	que.push("(");

	vector<string> ans{};

	while (!que.empty())
	{
		string cur = que.front();
		que.pop();

		if (cur.length() == n * 2)
		{
			ans.push_back(cur);
			continue;
		}

		auto [nOpen, nClose] = countOpenClose(cur);

		if (nOpen < n)
		{
			que.push(cur + '(');
		}

		if (nClose < nOpen)
		{
			que.push(cur + ')');
		}
	}

	return ans;
}
```
1文字ずつ所望の文字列を作り上げていくような木を考える。
つまり、`1 < n`の場合、根は`(`で、その次のノードは`((`と`()`となる。
各ノードでは、`(`か`)`のどちらかを末尾にくっつけるようなノードをつなげていく。

所望の文字数（`n * 2`）になったら終わり。

### 2. 再帰
```cpp
void backtrack(vector<string> &ans, string &&str, int n, int nOpen, int nClose)
{
	if (str.length() == n * 2)
	{
		ans.push_back(str);
	}

	if (nOpen < n)
	{
		backtrack(ans, str + '(', n, nOpen + 1, nClose);
	}
	if (nClose < nOpen)
	{
		backtrack(ans, str + ')', n, nOpen, nClose + 1);
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> ans{};
	backtrack(ans, "", n, 0, 0);
	return ans;
}
```
1.と考え方は同じだが、再帰による解法。
開く括弧と閉じる括弧の数を引数として扱っている。
