#include <unordered_set>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *node) : val(x), next(node) {}
};

// @lc code=start
class Solution
{
public:
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
};
// @lc code=end
