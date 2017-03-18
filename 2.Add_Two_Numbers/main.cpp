#include <iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

            // 建立新节点 cur，并加入链表，pre 指针在链表上后移
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

class Test {
public:
    ListNode* input1;
    ListNode* input2;
    ListNode* key;
    ListNode* result;

public:
    Test() {
        this->input1 = createList(2, 4, 3);
        this->input2 = createList(5, 6, 4);
        this->key = createList(7, 0, 8);
    }

    ~Test() {
        this->input1 = NULL;
        this->input2 = NULL;
        this->key = NULL;
        this->result = NULL;
    }

    template<typename T>
    ListNode* createList(T a, T b, T c) {
        ListNode* head = new ListNode(a);
        ListNode* mid = new ListNode(b);
        ListNode* tail = new ListNode(c);

        head->next = mid;
        mid->next = tail;

        return head;
    }

    bool check() {
        bool flag = true;

        ListNode* i = this->result;
        ListNode* j = this->key;

        while (i != NULL && j != NULL) {
            if (i->val != j->val) {
                flag = false;
                break;
            }

            i = i->next;
            j = j->next;
        }

        return flag;
    }
};

int main()
{
    Test test;
    Solution solution;

    test.result = solution.addTwoNumbers(test.input1, test.input2);

    if (test.check())
        cout << "Success!" << endl;
    else
        cout << "Fail!" << endl;

    return 0;
}
