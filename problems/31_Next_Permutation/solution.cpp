/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        for (int i = nums.size() - 2; 0 <= i; --i)
        {
            // 右から順番に桁を増やしながら見ていき、
            // 「最後の順列」ではない場所を探す
            if (nums[i] < nums[i + 1])
            {
                // ピボットより大きく、かつ最小を探す
                // 右から順に大きくなるので右から見ればよい
                int swapIdx = nums.size() - 1;
                while (nums[swapIdx] <= nums[i])
                {
                    swapIdx--;
                }

                // ピボットと発見した数字を入れ替え
                swap(nums[i], nums[swapIdx]);

                // すると、ピボットはその部分配列で最小の値であり、かつ右に挿入されるため
                // 「右から順に大きくなる」という性質は維持されている
                // だから反転すれば「最初の順列」が得られる
                reverse(nums.begin() + (i + 1), nums.end());

                return;
            }
        }

        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
