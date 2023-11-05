## 問題
二分木が与えられたとき、その最小の深さを返せ。

最初の深さとは、根から最も近い葉への最短のパスである。

## 解法
### 1. 再帰
```cpp
int minDepth(TreeNode *root)
{
	if (!root)
	{
		return 0;
	}

	// 片方だけある場合
	if (root->left && !root->right)
	{
		return minDepth(root->left) + 1;
	}
	else if (!root->left && root->right)
	{
		return minDepth(root->right) + 1;
	}

	int leftMin = minDepth(root->left);
	int rightMin = minDepth(root->right);

	return min(leftMin, rightMin) + 1;
}
```
片方だけノードがある場合の考慮を忘れると答えがおかしくなる。
葉というのが子を持たないノードであることに注意。

片方だけノードがある場合のコードで、以下のようなのを書いていたが可読性が低すぎるのでやめた。
```cpp
if (!!root->left ^ !!root->right)
{
	return max(minDepth(root->left), minDepth(root->right)) + 1;
}
```
`!!`で強制的にboolにしつつ、`^`演算子でXORを取っている。
XORを使うコードなんて、人生で10回も使わなそう。
そして使うたびに調べる必要がありそう。

### 2. DFS
```cpp
int minDepth(TreeNode *root)
{
	if (!root)
	{
		return 0;
	}

	stack<pair<TreeNode *, int>> stack{};
	stack.push({root, 0});

	int min = 10000;
	while (!stack.empty())
	{
		auto [curNode, depth] = stack.top();
		stack.pop();

		if (!curNode)
		{
			continue;
		}

		if (!curNode->left && !curNode->right)
		{
			min = std::min(min, depth + 1);
			continue;
		}

		stack.push({curNode->left, depth + 1});
		stack.push({curNode->right, depth + 1});
	}

	return min;
}
```
葉でしか最小値更新をしないようにしている。

### 3. 再帰（より簡潔なコード）
```cpp
int minDepth(TreeNode *root)
{
	if (!root)
	{
		return 0;
	}

	if (root->left && root->right)
	{
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}

	return max(minDepth(root->left), minDepth(root->right)) + 1;
}
```
