/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
private:
    bool canShip(vector<int> &weights, int capacity, int days)
    {
        int total = 0;
        int count = 1;
        for (int w : weights)
        {
            total += w;
            if (capacity < total)
            {
                count++;
                total = w;
            }
        }
        return count <= days;
    };

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        if (weights.size() == 1)
        {
            return weights[0];
        }

        int total = 0;
        for (int w : weights)
        {
            total += w;
        }

        // とりうる積載重量の範囲で積載可能な最小値を二分探索
        // [最大値、総和]
        int start = *max_element(weights.begin(), weights.end());
        int last = total;
        int ans = 0;
        while (start <= last)
        {
            int mid = (start + last) / 2;
            if (canShip(weights, mid, days))
            {
                ans = mid;
                last = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
