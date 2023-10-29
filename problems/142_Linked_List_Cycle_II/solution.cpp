struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *node) : val(x), next(node) {}
};

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		if (head == NULL)
		{
			return NULL;
		}

		ListNode *fast = head;
		ListNode *slow = head;

		ListNode *fastOld = head;
		ListNode *slowOld = head;

		// サイクルの有無を判定
		while (fast != NULL)
		{
			if (fast->next == NULL || fast->next->next == NULL)
			{
				return NULL;
			}

			fastOld = fast;
			slowOld = slow;

			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
			{
				break;
			}
		}

		if (fast == NULL)
		{
			return NULL;
		}

		// slowを初期地点に戻し、fastは1つずつ移動させる
		// 重なった位置がサイクルの開始点
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}
};