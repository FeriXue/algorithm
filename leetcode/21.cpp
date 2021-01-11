#include <iostream>
#include <memory>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *aa = new ListNode(0, a);
        ListNode *fa = aa;
        while(a && b) {
            if (b->val < a->val) {
                ListNode *t = b->next;
                b->next = a;
                fa->next = b;
                fa = fa->next;
                b = t;
            } else {
                fa = a;
                a = a->next;
            }
        }
        while(b) {
            ListNode *t = b->next;
            fa->next = b;
            fa = fa->next;
            b = t;
        }
        return aa->next;
    }
};
