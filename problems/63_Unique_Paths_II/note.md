## 問題
`m x n`の整数配列`grid`を与えられる。
ロボットは初めは左上の隅（つまり`grid[0][0]`）に位置している。
ロボットは右下の隅に移動しようとする（つまり`grid[m - 1][n - 1]`）。
ロボットは1度に右か下にしか移動できない。

障害物と空間はそれぞれ`grid`の`1`と`0`でで占められる。
障害物のある経路をロボットは取ることができない。

右下の隅に移動できるユニークな経路の数を返せ。

答えが`2 * 10^9`以下になるようにテストケースは作成されている。

## 解法
### 1. DP
```cpp
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
	int h = obstacleGrid.size();
	int w = obstacleGrid[0].size();
	vector<vector<long long>> dp(h, vector<long long>(w, 0));

	// 端を初期化
	for (int x = w - 1; 0 <= x; --x)
	{
		if (obstacleGrid[h - 1][x] == 1)
		{
			break;
		}
		dp[h - 1][x] = 1;
	}
	for (int y = h - 1; 0 <= y; --y)
	{
		if (obstacleGrid[y][w - 1] == 1)
		{
			break;
		}
		dp[y][w - 1] = 1;
	}

	// 端以外の計算
	for (int x = w - 2; 0 <= x; --x)
	{
		for (int y = h - 2; 0 <= y; --y)
		{
			if (obstacleGrid[y][x])
			{
				dp[y][x] = 0;
				continue;
			}
			dp[y][x] = dp[y + 1][x] + dp[y][x + 1];
		}
	}

	return dp[0][0];
}
```
`62. Unique Paths`とほとんど同じ。
それぞれの座標において障害物の有無をチェックする部分が違うだけ。
