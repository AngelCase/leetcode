## 問題
昇順にソートされた連結リストに対して、
同じ要素が1つしか存在しない状態にして返せ。

## 解法
```cpp
ListNode *deleteDuplicates(ListNode *head)
{
	if (head == nullptr)
	{
		return head;
	}

	ListNode *cur = head;

	while (cur->next != nullptr)
	{
		if (cur->val == cur->next->val)
		{
			cur->next = cur->next->next;
		}
		else
		{
			cur = cur->next;
		}
	}

	return head;
}
```
