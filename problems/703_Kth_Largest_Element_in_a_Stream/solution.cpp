/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class KthLargest
{
private:
	int k;
	// 昇順の優先順位付きキュー
	priority_queue<int, vector<int>, greater<int>> que;

public:
	KthLargest(int k, vector<int> &nums)
		: k(k),
		  que(priority_queue<int, vector<int>, greater<int>>{nums.begin(), nums.end()})
	{
		for (int i = 0; k < que.size(); ++i)
		{
			que.pop();
		}
	}

	int add(int val)
	{
		que.push(val);
		if (k < que.size())
		{
			que.pop();
		}
		return que.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
