## 問題
昇順にソートされた連結リストに対して、
重複する数字のノード全てを削除し、
どのノードとも重複しない数字のノードのみ残して返せ。

## 解法
### 1回目
```cpp
ListNode *deleteDuplicates(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	if (head->val == head->next->val &&
		head->next->next == nullptr)
	{
		return nullptr;
	}

	ListNode *answer = nullptr;

	bool isDuplicated = false;
	ListNode *valStart = head;
	ListNode *cur = head->next;

	while (cur != nullptr)
	{
		if (valStart->val == cur->val)
		{
			isDuplicated = true;
			cur = cur->next;
			continue;
		}

		if (!isDuplicated)
		{
			// push back
			if (answer == nullptr)
			{
				answer = new ListNode(valStart->val, nullptr);
			}
			else
			{
				ListNode *end = answer;
				while (end->next != nullptr)
				{
					end = end->next;
				}
				end->next = new ListNode(valStart->val, nullptr);
			}
		}

		valStart = cur;
		cur = cur->next;
		isDuplicated = false;
	}

	if (!isDuplicated)
	{
		// push back
		if (answer == nullptr)
		{
			answer = new ListNode(valStart->val, nullptr);
		}
		else
		{
			ListNode *end = answer;
			while (end->next != nullptr)
			{
				end = end->next;
			}
			end->next = new ListNode(valStart->val, nullptr);
		}
	}

	return answer;
}
```
メモリ消費は大きいが速度は最速だった。
コードの共通化のできていない部分もある。

### 模範解答
```cpp
class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		ListNode *dummyHead = new ListNode(0, head);
		ListNode *cur = dummyHead;

		while (cur->next != nullptr && cur->next->next != nullptr)
		{
			// 重複があった場合、重複分を消す
			if (cur->next->val == cur->next->next->val)
			{
				// 重複の最後を探す
				ListNode *last = cur->next;
				while (last->next != nullptr && last->val == last->next->val)
				{
					last = last->next;
				}
				cur->next = last->next;
			}
			// 重複が無かった場合、次へ
			else
			{
				cur = cur->next;
			}
		}

		return dummyHead->next;
	}
};
```
連結リストへの要素追加をやりやすくするためにダミー要素を先頭に入れておき、
return時にはそのnextを渡しているのがミソ。
