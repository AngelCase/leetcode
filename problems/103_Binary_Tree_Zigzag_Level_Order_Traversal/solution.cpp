/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> que{};
        que.push(root);
        vector<vector<int>> ans{};

        bool l2r = true;
        int level = 0;
        while (!que.empty())
        {
            int s = que.size();
            vector<int> vec{};
            for (int i = 0; i < s; ++i)
            {
                TreeNode *node = que.front();
                que.pop();

                if (!node)
                {
                    continue;
                }

                if (l2r)
                {
                    vec.push_back(node->val);
                }
                else
                {
                    vec.insert(vec.begin(), node->val);
                }

                que.push(node->left);
                que.push(node->right);
            }

            if (0 < vec.size())
            {
                ans.push_back(vec);
            }

            ++level;
            l2r = !l2r;
        }

        return ans;
    }
};
// @lc code=end
