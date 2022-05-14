// https://leetcode.com/problems/remove-linked-list-elements/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if(!head) return nullptr;
//         ListNode *it = head;
//         while(it->next){
//             if(it->next->val == val) it->next = it->next->next;
//             else it = it->next;
//         }
//         return head->val == val ? head->next : head;
//     }
// };

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};