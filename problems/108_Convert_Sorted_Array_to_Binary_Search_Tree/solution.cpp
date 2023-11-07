/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }

        int center = nums.size() / 2;

        TreeNode *t = new TreeNode{nums[center]};

        if (0 < center)
        {
            vector<int> l{nums.begin(), nums.begin() + center};
            t->left = sortedArrayToBST(l);
        }

        if (center + 1 < nums.size())
        {
            vector<int> r{nums.begin() + center + 1, nums.end()};
            t->right = sortedArrayToBST(r);
        }

        return t;
    }
};
// @lc code=end
