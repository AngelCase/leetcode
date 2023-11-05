## 問題
`m x n`のバイナリ行列`grid`が与えられる。
島は陸を表す`1`の垂直と水平につながった集合である。
グリッドの4つの端全てが水に囲われているとみなせる。

島の面積は島の`1`のセルの数である。

`gird`の島のうち、最も大きい島の面積を返せ。
もし島が無ければ、`0`を返せ。

## 解法
### DFS
```cpp
int DFS(int area, vector<vector<int>> &grid, int x, int y)
{
	if (x < 0 || y < 0 || grid[0].size() <= x || grid.size() <= y || grid[y][x] != 1)
	{
		return area;
	}

	area++;
	grid[y][x] = 0;

	area = DFS(area, grid, x - 1, y);
	area = DFS(area, grid, x, y - 1);
	area = DFS(area, grid, x + 1, y);
	area = DFS(area, grid, x, y + 1);

	return area;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
	int max = 0;

	for (int y = 0; y < grid.size(); ++y)
	{
		for (int x = 0; x < grid[0].size(); ++x)
		{
			if (grid[y][x] == 1)
			{
				int area = DFS(0, grid, x, y);
				max = std::max(max, area);
			}
		}
	}

	return max;
}
```
