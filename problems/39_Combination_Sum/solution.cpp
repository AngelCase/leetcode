/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include <vector>
#include <stack>
#include <numeric>

using namespace std;

// @lc code=start
class Solution
{
private:
    void helper(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &cur, int target, int total)
    {
        if (total == target)
        {
            ans.push_back(cur);
            return;
        }
        if (candidates.empty() || target < total)
        {
            return;
        }

        // 選択肢の先頭を加えて条件を満たすか試す
        cur.push_back(candidates[0]);
        helper(ans, candidates, cur, target, total + candidates[0]);

        // 1手戻し、重複がないよう選択肢を1つ減らして次へ
        int first = candidates[0];
        candidates.erase(candidates.begin());
        cur.pop_back();
        helper(ans, candidates, cur, target, total);

        // 選択肢は元に戻す
        candidates.insert(candidates.begin(), first);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans{};
        vector<int> cur{};

        helper(ans, candidates, cur, target, 0);

        return ans;
    }
};
// @lc code=end
