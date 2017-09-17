/*
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
 *
 * algorithms
 * Medium (29.39%)
 * Total Accepted:    116K
 * Total Submissions: 392.5K
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
        if (!head || !head->next) return head;

        ListNode** point = &head;

        while (*point) {
            if ((*point)->next && (*point)->next->val == (*point)->val) {
                ListNode* tmp = *point;
                while (tmp && tmp->val == (*point)->val)
                    tmp = tmp->next;
                *point = tmp;
            } else {
                point = &((*point)->next);
            }
        }

        return head;
    }
};
