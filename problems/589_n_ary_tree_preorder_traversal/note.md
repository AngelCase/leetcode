## 問題
n分木の`root`が与えられたとき、
ノードの値を行きがけ順序（preorder）で返せ。

n分木のシリアル化はレベル順序の横断で表される。
子の各グループはnullで区切られる。

例：
```
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
```

## 閃き
再帰の方が簡単。
図を書いてどういう風に答えが蓄積されるのかを追っていくとイメージがしやすい。

## 解法
### 1. iterative
```cpp
vector<int> preorder(Node *root)
{
	if (root == nullptr)
	{
		return {};
	}

	vector<Node *> open{};
	open.push_back(root);

	vector<int> ans{};
	while (!open.empty())
	{
		Node *cur = open.front();
		open.erase(open.begin());

		ans.push_back(cur->val);

		// childrenをopenに結合
		open.insert(open.begin(), cur->children.begin(), cur->children.end());
	}

	return ans;
}
```

### 2. recursive
```cpp
vector<int> preorder(Node *root)
{
	if (!root)
	{
		return {};
	}

	vector<int> ans{};
	ans.insert(ans.begin(), root->val);

	for (auto child : root->children)
	{
		vector<int> result = preorder(child);
		ans.insert(ans.end(), result.begin(), result.end());
	}

	return ans;
}
```

## 学び
