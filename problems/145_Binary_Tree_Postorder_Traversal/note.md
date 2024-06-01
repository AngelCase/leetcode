## 問題
二分木の`root`が与えられたとき、
ノードの値を帰りがけ順に横断して返せ。

## 閃き
再帰が簡単。
反復で解く場合、既に巡回済みか？のメモをとること。

## 解法
### 1. recursive
```cpp
vector<int> postorderTraversal(TreeNode *root)
{
	if (!root)
	{
		return {};
	}

	vector<int> ret = {};

	vector<int> left = postorderTraversal(root->left);
	vector<int> right = postorderTraversal(root->right);

	ret.insert(ret.end(), left.begin(), left.end());
	ret.insert(ret.end(), right.begin(), right.end());
	ret.insert(ret.end(), root->val);

	return ret;
}
```

### 2. iterative
```cpp
vector<int> postorderTraversal(TreeNode *root)
{
	if (!root)
	{
		return {};
	}

	vector<int> ret = {};

	using isChecked = bool;
	stack<pair<TreeNode *, isChecked>> open = {};
	open.push({root, false});

	while (!open.empty())
	{
		auto [cur, isChecked] = open.top();
		open.pop();

		if (!cur)
		{
			continue;
		}

		if (isChecked ||
			(!cur->left && !cur->right))
		{
			ret.push_back(cur->val);
			continue;
		}

		open.push({cur, true});
		open.push({cur->right, false});
		open.push({cur->left, false});
	}

	return ret;
}
```
巡回済みか？のメモを利用する。

## 学び
