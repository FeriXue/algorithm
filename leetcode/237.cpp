#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto t = node->next;
        swap(node->val, t->val);
        node->next = t->next;
        delete t;            
    }
};
