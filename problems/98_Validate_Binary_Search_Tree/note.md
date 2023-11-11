## 問題
二分木の`root`が与えられた時、
それが有効な二分探索木（BST: Binary Search Tree）かを返せ。

有効な二分探索木は以下のように定義される：
- ノードの左の部分木はそのノードのキーより小さいキーのノードのみが含まれる。
- ノードの右の部分木はそのノードのキーより大きいキーのノードのみが含まれる。
- 左と右の部分木はどちらも二分探索木となっている。

## 解法
### 1. 再帰
```cpp
int searchMax(TreeNode *root)
{
	if (!root->right)
	{
		return root->val;
	}
	return searchMax(root->right);
}

int searchMin(TreeNode *root)
{
	if (!root->left)
	{
		return root->val;
	}
	return searchMin(root->left);
}

bool isValidBST(TreeNode *root)
{
	bool left = !root->left ||
				(searchMax(root->left) < root->val && isValidBST(root->left));

	bool right = !root->right ||
					(root->val < searchMin(root->right) && isValidBST(root->right));

	return left && right;
}
```
各ノードで以下を満たしていればBSTとみなす。
- 左の部分木がBSTで、かつその最大値が自身より小さい
- 右の部分木がBSTで、かつその最小値が自身より大きい
このBSTチェックを全てのノードで再帰的に行う。

最大値・最小値を探す際も再帰を使っている。

## 学び
- 二分探索木
