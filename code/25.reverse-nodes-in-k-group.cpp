/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group
 *
 * Hard (30.41%)
 * Total Accepted:    93192
 * Total Submissions: 306194
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * 
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be
 * changed.
 * 
 * Only constant memory is allowed.
 * 
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * 
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * 
 * 
 * For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* begin = new ListNode(0);
        begin->next = head;
        ListNode* pre = begin, * a = begin, * b;
        int num = 0;

        while (a = a->next) num++;
        while (num >= k) {
            a = pre->next;

            for (int i = 1; i < k; i++) {
                b = a->next;
                a->next = b->next;
                b->next = pre->next;
                pre->next = b;
            }
            pre = a;
            num -= k;
        }

        return begin->next;
    }
};
