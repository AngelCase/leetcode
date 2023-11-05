## 問題
`1`で陸、`0`で水を表現した 
`m x n`の二次元のバイナリグリッド`grid`が与えられたとき、
島の数を返せ。

島は水に囲まれていて、
水平か垂直につながった隣接する陸から構成される。
グリッドの四隅は水に囲まれていると考えてよい。

## 解法
### BFSによる解法
```cpp
void check(vector<vector<char>> &grid, int x, int y)
{
	grid[y][x] = '#';
	if (0 <= x - 1 && grid[y][x - 1] == '1')
	{
		check(grid, x - 1, y);
	}
	if (0 <= y - 1 && grid[y - 1][x] == '1')
	{
		check(grid, x, y - 1);
	}
	if (x + 1 < grid[0].size() && grid[y][x + 1] == '1')
	{
		check(grid, x + 1, y);
	}
	if (y + 1 < grid.size() && grid[y + 1][x] == '1')
	{
		check(grid, x, y + 1);
	}
}

int numIslands(vector<vector<char>> &grid)
{
	int count = 0;

	for (int y = 0; y < grid.size(); ++y)
	{
		for (int x = 0; x < grid[0].size(); ++x)
		{
			if (grid[y][x] == '1')
			{
				count++;
				check(grid, x, y);
			}
		}
	}

	return count;
}
```

## 学び
### unordered_setのキーにpairを渡すことはできない
unordered_setはハッシュマップであるため
ハッシュ関数が定義されていないpairはそのままだと使えない。
