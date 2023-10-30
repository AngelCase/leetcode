## 問題
与えられた連結リストを逆順にして返せ。

## 解法
### stackの利用
```cpp
ListNode *reverseList(ListNode *head)
{
	if (head == nullptr)
	{
		return head;
	}

	std::stack<int> stack{};
	while (head != nullptr)
	{
		stack.push(head->val);

		head = head->next;
	}

	ListNode *dummyHead = new ListNode(0);
	ListNode *ptr = dummyHead;
	while (!stack.empty())
	{
		ptr->next = new ListNode(stack.top());

		stack.pop();
		ptr = ptr->next;
	}

	return dummyHead->next;
}
```

### 再帰
```cpp
ListNode *reverseList(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	// 末尾のノードを得る
	ListNode *ret = reverseList(head->next);

	head->next->next = head;
	head->next = nullptr;
	return ret;
}
```

### 逐次更新
```cpp
ListNode *reverseList(ListNode *head)
{
	ListNode *cur = head;
	ListNode *prev = nullptr;

	while (cur != nullptr)
	{
		ListNode *next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}
```
