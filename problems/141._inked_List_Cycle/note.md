## 問題
連結リストのheadが与えられるので、
その連結リストにサイクルがあるかを判定せよ。

## 解法
### 1. ノード数の上限までノードを移動する
```cpp
bool hasCycle(ListNode *head)
{
	std::unordered_set<intptr_t> us{};
	ListNode *cur = head;
	if (cur == NULL)
	{
		return false;
	}

	for (int i = 0; i < 10000; i++)
	{
		if (cur->next == NULL)
		{
			return false;
		}
		cur = cur->next;
	}
	return true;
}
```
ノードの数が取りうる範囲は[0, 10^4]。
つまり、ノードの数が10^4を超えたら、サイクルがあると判断できる。

### 2. フロイドの循環検出法
```cpp
bool hasCycle(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return false;
	}

	ListNode *rabbit = head->next;
	ListNode *turtle = head;

	while (rabbit != turtle)
	{
		if (rabbit->next == NULL || rabbit->next->next == NULL)
		{
			return false;
		}

		rabbit = rabbit->next->next;
		turtle = turtle->next;
	}
	return true;
}
```

## 学び
### フロイドの循環検出法
1倍速で動くポインタと、2倍速で動くポインタを用意すれば、
ループが存在するとき必ずいつかは同じポインタを指すことを利用したアルゴリズム。
ウサギとカメのアルゴリズムという愛称もある。
