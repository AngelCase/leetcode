## 問題
二分木の`root`と整数`targetSum`が与えられた時、
値を足し上げたら`targetSum`と同じになるような根から葉までのパスがあれば
`true`を返せ。

なお、葉は子を持たないノードである。

## 解法
### 1. DFS
```cpp
bool hasPathSum(TreeNode *root, int targetSum)
{
	if (!root)
	{
		return false;
	}

	stack<pair<TreeNode *, int>> open{};
	open.push({root, 0});

	while (!open.empty())
	{
		auto [cur, total] = open.top();
		open.pop();

		if (!cur)
		{
			continue;
		}

		total += cur->val;

		if (!cur->left && !cur->right && total == targetSum)
		{
			return true;
		}

		open.push({cur->left, total});
		open.push({cur->right, total});
	}

	return false;
}
```
1つでも条件を満たすパスを見つければよいので、
BFSよりもDFSの方が早く終わりそうだと感じDFSを選択。

### 2. 再帰
```cpp
bool hasPathSum(TreeNode *root, int targetSum)
{
	if (!root)
	{
		return false;
	}

	if (!root->left && !root->right && root->val == targetSum)
	{
		return true;
	}

	bool left = hasPathSum(root->left, targetSum - root->val);
	bool right = hasPathSum(root->right, targetSum - root->val);

	return left || right;
}
```
`targetSum`から値を引いているのがミソ。
また、1つでも条件を満たすパスがあればよいので、`return left || right`となっている。
