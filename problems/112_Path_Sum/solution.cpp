/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */
#include <stack>

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        if (!root->left && !root->right && root->val == targetSum)
        {
            return true;
        }

        bool left = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);

        return left || right;
    }
};
// @lc code=end
