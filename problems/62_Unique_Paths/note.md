## 問題
`m x n`のグリッド上にロボットがいる。
そのロボットははじめ左上の隅（つまり`grid[0][0]`）にいる。
ロボットは右下の隅（つまり`grid[m - 1][n - 1]`）に移動しようとする。
ロボットは一度に下か右のどちらかにしか進めない。

2つの整数`m`と`n`が与えられたとき、
右下の隅に進めるユニークな経路の数を返せ。

テストケースは答えが`2 * 10^9`以下になるように生成される。

## 解法
### 1. 組み合わせの数
この問題は右への移動と下への移動を並び替えた時のパターンがいくつあるか？ということなので
組み合わせの数の問題に帰着できる。

右へ移動する回数を`right`、下へ移動する回数を`down`とすると、
`right + down`から`right`を取り出す組み合わせの数として計算できる。
```cpp
int combination(int n, int r)
{
	long long ans = 1;
	for (int i = 1; i <= r; i++)
	{
		ans = ans * (n - r + i) / i;
	}
	return ans;
}

int uniquePaths(int m, int n)
{
	int dMove = m - 1;
	int rMove = n - 1;

	return combination(dMove + rMove, dMove);
}
```
組み合わせの計算がポイント。
素直に計算すると階乗が出てきて、
`long long`でも値が入りきらなくなる。

割算が必ず割り切れるあたりもポイント。
その理由は以下を繰り返せばイメージできる：
- `m * (m + 1)`は2で割り切れる。
- `m * (m + 1) * (m + 2)`は3で割り切れる（因数のうち、どれか1つは必ず3の倍数）。

### 2. DP
```cpp
int uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n, 1));

	for (int i = dp.size() - 2; 0 <= i; --i)
	{
		for (int j = dp[0].size() - 2; 0 <= j; --j)
		{
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}

	return dp[0][0];
}
```
グリッドのそれぞれの座標に対して「経路が何パターンあるか」を計算しメモする。
それぞれの座標での経路の数は右のメモと下のメモを足した合計で求められる。
右端と下端の経路は1パターンなので1で初期化しておく。

## 学び
### 組み合わせ
https://inupri.web.fc2.com/kakuritu/onajijyunretu.pdf
### パスカルの三角形
https://examist.jp/mathematics/expression-proof/pascal-triangle/
