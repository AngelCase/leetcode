## 問題
二分木の`root`が与えられたとき、
その最大の深さを返せ。

二分木の最大の深さとは、
根から最も遠くの葉までの最長パスでのノードの数である。

## 解法
### 1. 再帰
```cpp
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);

        return max(leftMax, rightMax) + 1;
    }
};
```

### 2. BFS
```cpp
int maxDepth(TreeNode *root)
{
	int max = 0;

	queue<pair<TreeNode *, int>> que{};
	que.push({root, 0});

	while (!que.empty())
	{
		auto [curNode, curDepth] = que.front();
		que.pop();

		if (curNode)
		{
			max = std::max(max, curDepth + 1);

			que.push({curNode->left, curDepth + 1});
			que.push({curNode->right, curDepth + 1});
		}
	}

	return max;
}
```
