class Solution {
	// iterative approach
	public ListNode reverseList(ListNode head) {
		if (head == null) {
			return null;
		}

		ListNode cur = head;
		ListNode prev = null;
		while (cur != null) {
			ListNode next = cur.next;

			// 逆順にする
			cur.next = prev;

			prev = cur;
			cur = next;
		}

		return prev;
	}

	// recursive approach
	public ListNode reverseListRecursively(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}

		ListNode tail = reverseList(head.next);
		head.next.next = head;
		head.next = null;

		return tail;
	}
}


class ListNode {
	int val;
	ListNode next;

	ListNode() {}

	ListNode(int val) {
		this.val = val;
	}

	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}
