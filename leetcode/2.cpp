#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:  
    ListNode *nn = nullptr;
    void get_dfs(ListNode *a, ListNode *b, ListNode *res, int &tag) 
    {
        if (a == nullptr) {
            nn = b;
            return;
        }
        if (b == nullptr) {
            nn = a;
            return;
        }
        int t = a->val + b->val + tag;
        if (t >= 10) {
            t %= 10;
            tag = 1;
        } else {
            tag = 0;
        }
        auto q = new ListNode(t, res->next);
        res->next = q;
        a = a->next;
        b = b->next;
        get_dfs(a, b, res->next, tag);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        auto t = res, begin = res;
        int tag = 0;
        get_dfs(l1, l2, t, tag);

        ListNode *last;
        while (begin != nullptr) {
            last = begin;
            begin = begin->next;
        }

        while (nn != nullptr) {
            int zhi = nn->val + tag;
            if (zhi >= 10) {
                zhi %= 10;
                tag = 1;
               } else {
                  tag = 0;
            }          
            auto temp = new ListNode(zhi, nullptr);
            last->next = temp;
            last = temp;
            nn = nn->next;
        }
        
        if (tag) {
            auto temp = new ListNode(tag, nullptr);
            last->next = temp;
            last = temp;   
        }

        return res->next;
    }
};
