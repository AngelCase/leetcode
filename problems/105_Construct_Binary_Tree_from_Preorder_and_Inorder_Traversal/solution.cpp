/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */
#include <vector>
#include <queue>
#include <unordered_map>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = new TreeNode{preorder[0]};

        int inIdx = 0;
        for (int i = 0;; ++i)
        {
            if (inorder[i] == root->val)
            {
                inIdx = i;
                break;
            }
        }

        if (1 < preorder.size() && 0 < inIdx)
        {
            vector<int> nextPreorder{preorder.begin() + 1, preorder.end()};
            vector<int> nextInorder{inorder.begin(), inorder.begin() + inIdx};
            root->left = buildTree(nextPreorder, nextInorder);
        }
        int leftSize = inIdx;
        if (leftSize + 1 < preorder.size() && inIdx < inorder.size() - 1)
        {
            vector<int> nextPreorder{preorder.begin() + leftSize + 1, preorder.end()};
            vector<int> nextInorder{inorder.begin() + inIdx + 1, inorder.end()};
            root->right = buildTree(nextPreorder, nextInorder);
        }

        return root;
    }
};
// @lc code=end
