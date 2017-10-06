/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii
 *
 * algorithms
 * Medium (30.62%)
 * Total Accepted:    119.9K
 * Total Submissions: 388.3K
 * Testcase Example:  '[5]\n1\n1'
 *
 * 
 * Reverse a linked list from position m to n. Do it in-place and in
 * one-pass.
 * 
 * 
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode begin(0);
        begin.next = head;

        ListNode* pre = &begin;
        for (int i = 0; i < m - 1; ++i) pre = pre->next;
        ListNode* cur = pre->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }

        return begin.next;
    }
};
