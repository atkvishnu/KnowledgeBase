// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root) pre(root, &ans);
        return ans;
    }
    void pre(Node* node, vector<int>* ans) {
        ans->push_back(node->val);
        for (Node* child : node->children)
            pre(child, ans);
    }
};

// class Solution {
// public:
//     vector<int> preorder(Node* root) {
//         if(!root) return {};
//         vector<int> result;
//         stack<Node*> stk{{root}};
//         while(!stk.empty()) {
//             Node *ptr = stk.top();
//             stk.pop();
//             result.push_back(ptr->val);
//             for(int i = (int)ptr->children.size()-1; i >= 0; i--) {
//                 stk.push(ptr->children[i]);
//             }
//         }
//         return result;
//     }
// };