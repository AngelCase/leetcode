## 問題
要素が昇順ソートされた整数配列`nums`が与えられたとき、
それをheight-balanced 二分探索木へと変換せよ。

height-balanced binary treeとは全てのノードの2つの部分木の深さが
1以下の差であるような二分木である。

`nums`は厳格に昇順ソートされる。

## 解法
### 1. 再帰
```cpp
TreeNode *sortedArrayToBST(vector<int> &nums)
{
	if (nums.empty())
	{
		return nullptr;
	}

	int center = nums.size() / 2;

	TreeNode *t = new TreeNode{nums[center]};

	if (0 < center)
	{
		vector<int> l{nums.begin(), nums.begin() + center};
		t->left = sortedArrayToBST(l);
	}

	if (center + 1 < nums.size())
	{
		vector<int> r{nums.begin() + center + 1, nums.end()};
		t->right = sortedArrayToBST(r);
	}

	return t;
}
```
ソートされているので半分に割って、左側と右側の部分木でも同じことを繰り返す。

## 学び
### 二分探索木
親の左側のノードが親よりも小さく、右側のノードの値が親よりも大きい二分木。
