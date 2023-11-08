## 問題
二分木の`root`が与えられたとき、
そのレベル順にノードの値を横断したものを返せ。
（つまり、左から右へ、レベルごとに）

## 解法
### 1. 再帰
```cpp
void pushByOrder(vector<vector<int>> &ans, TreeNode *node, int level)
{
	if (!node)
	{
		return;
	}

	if (ans.size() <= level)
	{
		ans.push_back(vector<int>{});
	}
	ans[level].push_back(node->val);

	pushByOrder(ans, node->left, level + 1);
	pushByOrder(ans, node->right, level + 1);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
	vector<vector<int>> ans{};

	pushByOrder(ans, root, 0);

	return ans;
}
```

### 2. BFS
```cpp
vector<vector<int>> levelOrder(TreeNode *root)
{
	queue<pair<TreeNode *, int>> que{};
	que.push({root, 0});

	vector<vector<int>> ans{};

	while (!que.empty())
	{
		auto [node, level] = que.front();
		que.pop();

		if (!node)
		{
			continue;
		}

		if (ans.size() <= level)
		{
			ans.push_back(vector<int>{});
		}
		ans[level].push_back(node->val);

		que.push({node->left, level + 1});
		que.push({node->right, level + 1});
	}

	return ans;
}
```

### その他、細かい部分の実装
他の人の解法を見ていて、なるほどなと思った部分。
```cpp
while (!q.empty())
{
	int s = q.size();
	vector<int> v;
	for (int i = -1; i < s; i++)
	{
		TreeNode *node = q.front();
		q.pop();
		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
		v.push_back(node->val);
	}
	ans.push_back(v);
}
```
自分は`ans`の要素外に触れることが無いよう、適宜`push_back()`して要素を増やしていたが、
この例ではそうではなく`q`の要素数を先に取っておき、
それを`for`で回すことでレベルごとに処理していく、ということを実現している。
