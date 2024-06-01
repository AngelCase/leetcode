/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */
#include <vector>
#include <stack>
#include <ciso646>
using namespace std;

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        vector<int> ret = {};

        using isChecked = bool;
        stack<pair<TreeNode *, isChecked>> open = {};
        open.push({root, false});

        while (!open.empty())
        {
            auto [cur, isChecked] = open.top();
            open.pop();

            if (!cur)
            {
                continue;
            }

            if (isChecked ||
                (!cur->left && !cur->right))
            {
                ret.push_back(cur->val);
                continue;
            }

            open.push({cur, true});
            open.push({cur->right, false});
            open.push({cur->left, false});
        }

        return ret;
    }
};
// @lc code=end

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};