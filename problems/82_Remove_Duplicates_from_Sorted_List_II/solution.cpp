struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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