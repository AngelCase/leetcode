class Solution {
	private ListNode findAnother(int val, ListNode node) {
		if (node == null) {
			return null;
		}

		if (val == node.val) {
			return findAnother(val, node.next);
		}

		return node;
	}

	public ListNode deleteDuplicates(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}

		// valは[-100,100]なので、無効値としてその範囲外の値で初期化
		final int INVALID_NUM = 200;
		ListNode dummyHead = new ListNode(INVALID_NUM, head);

		ListNode prev = dummyHead;
		ListNode cur = dummyHead.next;
		while (cur != null && cur.next != null) {
			// 同じ値を持つノードが出てきたら、
			// 異なる値のノードを探してprevにつなぐ
			if (cur.val == cur.next.val) {
				prev.next = findAnother(cur.val, cur.next.next);
				cur = prev.next;
				continue;
			}

			prev = cur;
			cur = cur.next;
		}

		return dummyHead.next;
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
