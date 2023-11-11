## 問題
2つの整数配列`preorder`と`inorder`が与えられる。
`preorder`は二分木のpreorder横断、
`inorder`は同じ二分木のinorder横断である。
その二分木を構築して返せ。

## 解法
### 1. BFS
```cpp
// 値がinorderだと何番目か？のマップ
unordered_map<int, int> val2inorderIdx{};

TreeNode *BFS(TreeNode *root, int num)
{
	queue<TreeNode *> open{};
	open.push(root);
	while (!open.empty())
	{
		TreeNode *cur = open.front();
		open.pop();

		if (!cur)
		{
			continue;
		}

		// 空きがあるならinorderを満たすかチェック
		if (!cur->left &&
			val2inorderIdx[num] < val2inorderIdx[cur->val])
		{
			cur->left = new TreeNode{num};
			break;
		}
		if (!cur->right &&
			val2inorderIdx[cur->val] < val2inorderIdx[num])
		{
			cur->right = new TreeNode{num};
			break;
		}

		// preorderなので既に右が埋まっている場合、左には絶対来ない
		if (!cur->right)
		{
			open.push(cur->left);
		}
		open.push(cur->right);
	}

	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
	TreeNode *ans = new TreeNode{preorder.front()};

	for (int i = 0; i < inorder.size(); ++i)
	{
		val2inorderIdx.emplace(inorder[i], i);
	}

	vector<int> arr{preorder.begin() + 1, preorder.end()};
	for (int num : arr)
	{
		ans = BFS(ans, num);
	}

	return ans;
}
```
根はpreorderの先頭。

preorderの値に対し、
BFSで二分木を探索した時、inorderの順序を満たすように配置する。
ただし、ノードの右に要素がつながっている場合、
そのノードの左には追加しない。

inorderの順序確認を毎回しなくて済むよう、
あらかじめ値とinorderでの順位の対応をunorder_mapに記録している。

### 2. 再帰
```cpp
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
	TreeNode *root = new TreeNode{preorder[0]};

	int inIdx = 0;
	for (int i = 0;; ++i)
	{
		if (inorder[i] == root->val)
		{
			inIdx = i;
			break;
		}
	}

	if (1 < preorder.size() && 0 < inIdx)
	{
		vector<int> nextPreorder{preorder.begin() + 1, preorder.end()};
		vector<int> nextInorder{inorder.begin(), inorder.begin() + inIdx};
		root->left = buildTree(nextPreorder, nextInorder);
	}
	int leftSize = inIdx;
	if (leftSize + 1 < preorder.size() && inIdx < inorder.size() - 1)
	{
		vector<int> nextPreorder{preorder.begin() + leftSize + 1, preorder.end()};
		vector<int> nextInorder{inorder.begin() + inIdx + 1, inorder.end()};
		root->right = buildTree(nextPreorder, nextInorder);
	}

	return root;
}
```
「preorderの先頭の値は必ずノードの根になる」という性質を利用し、
木を左の部分木と右の部分木に分け、preorderの先頭を繋げていく解法。

部分木のinorderは、根から左と右で分けるだけなので簡単に導ける。
左の部分木のpreorderも先頭要素を省くだけなので簡単。
右の部分木のpreorderは、
左の部分木のサイズをもとに計算する必要がある点に注意。

## 学び
### 二分木の巡回方法
大別すると幅優先探索と深さ優先探索の2つ。
さらに幅優先探索はpreorder、inorder、postorderの3つに分類できるので
細かい分類だと4つ。
#### preorder
次の優先順位で処理をおこなった際の順序。
1. データを見る
2. 左へ移動
3. 右へ移動
または、反時計回りにグラフを囲った時ノードの「左」を通った順序。
#### inorder
次の優先順位で処理をおこなった際の順序。
1. 左へ移動
2. データを見る
3. 右へ移動
または、反時計回りにグラフを囲った時ノードの「下」を通った順序。
#### postorder
次の優先順位で移動したとき、移動できなくなったらデータを見る場合の順序。
1. 左へ移動
2. 右へ移動
または、反時計回りにグラフを囲った時ノードの「右」を通った順序。
#### 幅優先探索
割愛。
#### 参考
[うさぎでもわかる2分探索木　後編　2分探索木における4つの走査方法 | 工業大学生ももやまのうさぎ塾 (momoyama-usagi.com)](https://www.momoyama-usagi.com/entry/info-algo-tree-traverse)