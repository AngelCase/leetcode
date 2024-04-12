## 問題
二分木の`root`が与えられたとき、
ノードの値を通りがけ順に横断して返せ。

## 閃き
再帰で解くと超簡単。
反復的に解く場合、必ず戻ってくる必要があるのでどう戻るかがキモ。

## 解法
### 1. iterative
```cpp
vector<int> inorderTraversal(TreeNode *root)
{
	if (!root)
	{
		return {};
	}

	using isChecked = bool;
	stack<pair<TreeNode *, isChecked>> open{};
	open.push({root, false});

	vector<int> ans{};
	while (!open.empty())
	{
		auto [cur, isChecked] = open.top();
		open.pop();

		if (not cur)
		{
			continue;
		}

		if (isChecked || not cur->left)
		{
			ans.push_back(cur->val);
		}

		// 右、自分、左の順でスタック
		if (not isChecked)
		{
			open.push({cur->right, false});
			if (cur->left)
			{
				open.push({cur, true});
				open.push({cur->left, false});
			}
		}
	}

	return ans;
}
```
左にノードがある場合、自分を再びオープンキューに追加する。
その際、既に巡回済みのノードであることをメモしておき、
巡回済みであれば答えに自分の値を書き込んでよい。

### 2. recursive
```cpp
vector<int> inorderTraversal(TreeNode *root)
{
	if (not root)
	{
		return {};
	}
	vector<int> ans = inorderTraversal(root->left);
	ans.push_back(root->val);
	vector<int> right = inorderTraversal(root->right);
	ans.insert(ans.end(), right.begin(), right.end());

	return ans;
}
```

## 学び
