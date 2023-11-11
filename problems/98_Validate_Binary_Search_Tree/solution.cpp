/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
#include <queue>

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
    int searchMax(TreeNode *root)
    {
        if (!root->right)
        {
            return root->val;
        }
        return searchMax(root->right);
    }

    int searchMin(TreeNode *root)
    {
        if (!root->left)
        {
            return root->val;
        }
        return searchMin(root->left);
    }

    bool isValidBST(TreeNode *root)
    {
        bool left = !root->left ||
                    (searchMax(root->left) < root->val && isValidBST(root->left));

        bool right = !root->right ||
                     (root->val < searchMin(root->right) && isValidBST(root->right));

        return left && right;
    }
};
// @lc code=end
