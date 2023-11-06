## 問題
2つの二分木`root1`と`root2`が与えられる。

それらの一つをもう片方を覆うように配置すると、
いくつかのノードは重なるがそれ以外は重ならないことを想像せよ。
2つの木を1つの新しい二分木にマージする必要がある。
マージのルールは、
もし2つのノードが重なるなら、マージされたノードの新しい値は
その合計となる。
そうでなければ、nullでないノードが新しい木のノードとなる。

マージ後の木を返せ。

マージ処理はそれぞれの木の根から始める必要がある。

## 解法
### 1. 再帰（新しく木を作る）
```cpp
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
	if (!root1 && !root2)
	{
		return nullptr;
	}

	int val1 = root1 ? root1->val : 0;
	int val2 = root2 ? root2->val : 0;

	TreeNode *t = new TreeNode{val1 + val2};

	t->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
	t->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);

	return t;
}
```
既存の木を利用しない場合、再帰でないと難しい。
BFSなどをやろうとしても、ノード同士のつながりを作るのが困難。

### 2. BFS（root1にマージ）
```cpp
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
	if (!root1 && !root2)
	{
		return nullptr;
	}
	if (!root1 && root2)
	{
		return root2;
	}
	if (root1 && !root2)
	{
		return root1;
	}

	queue<TreeNode *> que1{};
	queue<TreeNode *> que2{};
	que1.push(root1);
	que2.push(root2);

	while (!que1.empty() && !que2.empty())
	{
		TreeNode *cur1 = que1.front();
		TreeNode *cur2 = que2.front();
		que1.pop();
		que2.pop();

		cur1->val += cur2->val;

		if (!cur1->left && cur2->left)
		{
			cur1->left = cur2->left;
		}
		else if (cur1->left && cur2->left)
		{
			que1.push(cur1->left);
			que2.push(cur2->left);
		}

		if (!cur1->right && cur2->right)
		{
			cur1->right = cur2->right;
		}
		else if (cur1->right && cur2->right)
		{
			que1.push(cur1->right);
			que2.push(cur2->right);
		}
	}

	return root1;
}
```
ノード同士のつながりを作るために、既存の木を利用する。
