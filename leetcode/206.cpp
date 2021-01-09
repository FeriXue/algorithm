#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode res{-1};
        ListNode *t = head;
        ListNode *tr = &res;

        while (t) {
            ListNode *temp = new ListNode(-1);
            temp->val = t->val;
            temp->next = tr->next;
            
            tr->next = temp;
            t = t->next;
        }

        return res.next;
    }
};

// 方法二

class Solute {
public:
    ListNode* reverseList(ListNode* head) {
        vector<ListNode *> que;
        ListNode *t = head;
        while (t) {
            que.push_back(t);
            t = t->next;
        }
        int i = 0, j = que.size() - 1;
        while (i < j) {
            swap(que[i ++]->val, que[j --]->val);
        }
        return head;
    }
};


