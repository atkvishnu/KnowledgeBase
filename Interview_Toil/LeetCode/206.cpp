// https://leetcode.com/problems/reverse-linked-list/

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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *q, *r;
        ListNode *p = head;
        q = r = nullptr;
        while (p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r; // reassigning
        }
        head = q;
        return head;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next) return head;
//         ListNode *newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return newHead;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *newHead = NULL;
//         while (head) {
//             ListNode *t = head->next;
//             head->next = newHead;
//             newHead = head;
//             head = t;
//         }
//         return newHead;
//     }
// };
