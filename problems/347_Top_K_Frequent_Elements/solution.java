import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
	public int[] topKFrequent(int[] nums, int k) {
		// 出現回数を調べる
		var map = new HashMap<Integer, Integer>();
		for (final int n : nums) {
			Integer curFreq = map.getOrDefault(n, 0);
			map.put(n, curFreq + 1);
		}

		// 出現回数順に並べる
		Comparator<Map.Entry<Integer, Integer>> comp =
				(lhs, rhs) -> rhs.getValue() - lhs.getValue();
		var que = new PriorityQueue<Map.Entry<Integer, Integer>>(comp);
		for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
			que.add(entry);
		}

		// 多い順にk個取り出す
		int[] retArr = new int[k];
		for (int i = 0; i < k; i++) {
			retArr[i] = que.poll().getKey();
		}

		return retArr;
	}
}

