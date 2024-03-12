import java.util.PriorityQueue;

class KthLargest {
	final int k;
	PriorityQueue<Integer> q;

	public KthLargest(int k, int[] nums) {
		this.k = k;

		q = new PriorityQueue<Integer>();
		for (int n : nums) {
			enqueue(n);
		}

	}

	public int add(int val) {
		q.add(val);
		if (k < q.size()) {
			q.poll();
		}
		return q.peek();
	}

	private void enqueue(int n) {
		q.add(n);
		while (k < q.size()) {
			q.poll();
		}
	}
}
