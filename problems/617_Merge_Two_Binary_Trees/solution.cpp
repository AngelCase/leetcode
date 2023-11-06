/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
        {
            return nullptr;
        }
        if (!root1 && root2)
        {
            return root2;
        }
        if (root1 && !root2)
        {
            return root1;
        }

        queue<TreeNode *> que1{};
        queue<TreeNode *> que2{};
        que1.push(root1);
        que2.push(root2);

        while (!que1.empty() && !que2.empty())
        {
            TreeNode *cur1 = que1.front();
            TreeNode *cur2 = que2.front();
            que1.pop();
            que2.pop();

            cur1->val += cur2->val;

            if (!cur1->left && cur2->left)
            {
                cur1->left = cur2->left;
            }
            else if (cur1->left && cur2->left)
            {
                que1.push(cur1->left);
                que2.push(cur2->left);
            }

            if (!cur1->right && cur2->right)
            {
                cur1->right = cur2->right;
            }
            else if (cur1->right && cur2->right)
            {
                que1.push(cur1->right);
                que2.push(cur2->right);
            }
        }

        return root1;
    }
};
// @lc code=end
