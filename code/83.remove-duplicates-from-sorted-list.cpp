/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 * algorithms
 * Easy (39.76%)
 * Total Accepted:    199.2K
 * Total Submissions: 498.7K
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) return head;

        ListNode** point = &head;

        while (*point) {
            if ((*point)->next && (*point)->next->val == (*point)->val)
                *point = (*point)->next;
            else
                point = &((*point)->next);
        }

        return head;
    }
};
