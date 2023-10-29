/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *ans = nullptr;
		ListNode *ansPtr = nullptr;

		ListNode *ptr1 = l1;
		ListNode *ptr2 = l2;

		bool kuriage = false;
		while (ptr1 != nullptr || ptr2 != nullptr || kuriage)
		{
			int digit1 = ptr1 != nullptr ? ptr1->val : 0;
			int digit2 = ptr2 != nullptr ? ptr2->val : 0;

			// この桁の合計を出す
			int sum = digit1 + digit2;
			if (kuriage)
			{
				sum += 1;
			}

			// 繰り上げの有無
			kuriage = 10 <= sum;

			// リスト末尾への追加
			int newVal = sum % 10;
			if (ans == nullptr)
			{
				ans = new ListNode{newVal};
				ansPtr = ans;
			}
			else
			{
				ansPtr->next = new ListNode{newVal};
				ansPtr = ansPtr->next;
			}

			// ポインタの移動
			if (ptr1 != nullptr)
			{
				ptr1 = ptr1->next;
			}
			if (ptr2 != nullptr)
			{
				ptr2 = ptr2->next;
			}
		}

		return ans;
	}
};
// @lc code=end
