/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers
 *
 * Medium (27.30%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* pre = head;
        ListNode* cur = pre;
        head->next = pre;

        bool carry = false;
        while (l1 != NULL || l2 != NULL) {
            int val = (l1 == NULL ? 0 : l1->val) +
                      (l2 == NULL ? 0 : l2->val) +
                      carry;
            carry = val > 9;
            val = val % 10;

            cur = (l1 == NULL ? l2 : l1);
            cur->val = val;
            pre->next = cur;
            pre = cur;

            l1 = (l1 == NULL ? l1 : l1->next);
            l2 = (l2 == NULL ? l2 : l2->next);
        }
        if (carry) {
            ListNode* tail = new ListNode(1);
            pre->next = tail;
        }

        return head->next;
    }
};
