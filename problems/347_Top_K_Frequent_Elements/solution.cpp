/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

// @lc code=start
class Solution
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		// 出現頻度を数える
		// 値、出現回数
		unordered_map<int, int> map{};
		for (auto num : nums)
		{
			++map[num];
		}

		vector<pair<int, int>> v{map.begin(), map.end()};
		nth_element(v.begin(), v.begin() + k, v.end(), [](auto &a, auto &b)
					{ return b.second < a.second; });

		vector<int> answer{};
		for (int i = 0; i < k; ++i)
		{
			answer.push_back(v.at(i).first);
		}

		return answer;
	}
};
// @lc code=end
