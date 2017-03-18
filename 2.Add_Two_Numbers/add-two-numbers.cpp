/* 注意 l1，l2 长度可能不同 */

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
