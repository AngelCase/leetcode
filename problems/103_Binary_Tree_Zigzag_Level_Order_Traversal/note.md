## 問題
二分木の`root`が与えられたとき、
ジグザグレベル順序にノードの値を横断したものを返せ。
（つまり、左から右に、次のレベルでは右から左にと交互に）

## 解法
### 1. BFS
```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
	queue<TreeNode *> que{};
	que.push(root);
	vector<vector<int>> ans{};

	bool l2r = true;
	int level = 0;
	while (!que.empty())
	{
		int s = que.size();
		vector<int> vec{};
		for (int i = 0; i < s; ++i)
		{
			TreeNode *node = que.front();
			que.pop();

			if (!node)
			{
				continue;
			}

			if (l2r)
			{
				vec.push_back(node->val);
			}
			else
			{
				vec.insert(vec.begin(), node->val);
			}

			que.push(node->left);
			que.push(node->right);
		}

		if (0 < vec.size())
		{
			ans.push_back(vec);
		}

		++level;
		l2r = !l2r;
	}

	return ans;
}
```
`int s = que.size();`で、レベルごとに処理しているところがミソ。
順序をジグザグにするため、`push_back()`と`insert()`を使い分けている。
