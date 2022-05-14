// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
//     void dfs(TreeNode *root){
//         if(!root) return;
//         answer.push_back(root->val);
//         dfs(root->left);
//         dfs(root->right);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         dfs(root);
//         return answer;
//     }
// };

// Follow Up!
// Iterative Approach
//      1
//    /   \
// null     2
//        /
//      3
// Preorder - [1,null,2,3]
// class Solution {
// public:
//     vector<int> res;
//     vector<int> preorderTraversal(TreeNode* root) {
//         if(!root) return {};
//         stack<TreeNode*> stk;
//         // Push root node to stack
//         TreeNode *p = root;
//         while(!stk.empty() || p) {
//             if(p) {         // if p is null, push p to stk, push val at p to res, go to left node
//                 stk.push(p);
//                 res.push_back(p->val);
//                 p = p->left;
//             } else {        // if p is null, make p as stk.top(), pop an elem from stack, and go to right node
//                 p = stk.top();
//                 stk.pop();
//                 p = p->right;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> stk{{root}};
        // Push root node to stack
        while(!stk.empty()) {
            TreeNode *temp = stk.top();
            stk.pop();
            res.push_back(temp->val);
            if(temp->right) stk.push(temp->right);
            if(temp->left) stk.push(temp->left);
        }
        return res;
    }
};

