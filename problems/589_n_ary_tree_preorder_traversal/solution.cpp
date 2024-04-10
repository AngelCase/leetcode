/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */
#include <vector>
#include <stack>
#include <list>
using namespace std;

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (!root)
        {
            return {};
        }

        vector<int> ans{};
        ans.insert(ans.begin(), root->val);

        for (auto child : root->children)
        {
            vector<int> result = preorder(child);
            ans.insert(ans.end(), result.begin(), result.end());
        }

        return ans;
    }
};
// @lc code=end

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};