/*
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list
 *
 * algorithms
 * Medium (24.34%)
 * Total Accepted:    113K
 * Total Submissions: 464.4K
 * Testcase Example:  '[]\n0'
 *
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head || NULL == head->next || 0 == k)
            return head;

        ListNode* node = head;
        int size = 1;

        while (node->next != NULL) {
            node = node->next;
            size++;
        }

        node->next = head;
        k = k % size;

        while (--size >= k)
            node = node->next;

        ListNode* ans = node->next;
        node->next = NULL;

        return ans;
    }
};
