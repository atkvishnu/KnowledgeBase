// https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// Recursive Approach
// class Solution {
// public:
//     vector<int> answer;
//     void search(TreeNode *root){
//         if(!root) return;
//         search(root->left);
//         answer.push_back(root->val);
//         search(root->right);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         search(root);
//         return answer;
//     }
// };

// Iterative Approach using stack
// left -> root -> right
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while (p || !stk.empty())
        {
            while (p)
            {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};

// TODO: morris traversal
// ! Morris Traversal has O(1) space complexity
// https://web.archive.org/web/20150308080843/http://noalgo.info/832.html
// https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html