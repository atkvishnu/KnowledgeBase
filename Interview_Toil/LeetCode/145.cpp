// https : // leetcode.com/problems/binary-tree-postorder-traversal/submissions/

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

// Recursive Solution
// class Solution {
// public:
//     vector<int> answer;
//     void search(TreeNode *root){
//         if(!root) return;
//         search(root->left);
//         search(root->right);
//         answer.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         search(root);
//         return answer;
//     }
// };

// Iterative Approach

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        stack<TreeNode *> s{{root}};
        TreeNode *head = root;
        while (!s.empty())
        {
            TreeNode *t = s.top();
            if ((!t->left && !t->right) || t->left == head || t->right == head)
            {
                res.push_back(t->val);
                s.pop();
                head = t;
            }
            else
            {
                if (t->right)
                    s.push(t->right);
                if (t->left)
                    s.push(t->left);
            }
        }
        return res;
    }
};
