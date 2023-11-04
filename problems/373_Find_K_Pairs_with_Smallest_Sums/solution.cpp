/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        auto comp = [](auto &a, auto &b)
        {
            return a.first + a.second < b.first + b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq{comp};

        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (pq.size() < k)
                {
                    pq.push({nums1.at(i), nums2.at(j)});
                }
                else if (pq.size() == k && nums1.at(i) + nums2.at(j) < pq.top().first + pq.top().second)
                {
                    pq.pop();
                    pq.push({nums1.at(i), nums2.at(j)});
                }
                else if (pq.size() == k && pq.top().first + pq.top().second < nums1.at(i) + nums2.at(j))
                {
                    break;
                }
            }
        }

        vector<vector<int>> ans{};
        while (0 < pq.size())
        {
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
