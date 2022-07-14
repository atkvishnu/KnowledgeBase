// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *last;
        ListNode *third;
        ListNode *first = list1;
        ListNode *second = list2;
        if (!list1 || !list2)
            return max(list1, list2);

        if (first->val <= second->val)
        {
            third = last = first;
            first = first->next;
            third->next = nullptr;
        }
        else
        {
            third = last = second;
            second = second->next;
            third->next = nullptr;
        }
        while (first && second)
        {
            if (first->val < second->val)
            {
                last->next = first;
                last = first;
                first = first->next;
                last->next = nullptr;
            }
            else
            {
                last->next = second;
                last = second;
                second = second->next;
                last->next = nullptr;
            }
        }
        if (first)
            last->next = first;
        if (second)
            last->next = second;
        return third;
    }
};