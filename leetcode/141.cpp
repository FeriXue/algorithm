#include <iostream>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// way1: 哈希表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode *, int> hash;
        ListNode *t = head;
        while (t) {
            if (hash.find(t) == hash.end()) {
                hash[t] = 1;
            } else {
                hash[t] = 2;
                return 1;
            }
            t = t->next;
        }       
        return false;
    }
};

// way2: 快慢指针解决环形链表
class Solutio {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return 0;
        }
        ListNode *t1 = head, *t2 = head;
        while (t1->next && t1->next->next) {
            t1 = t1->next->next;
            if (t1 == t2) {
                return 1;
            }
            t2 = t2->next;
        }
        return 0;
    }
};
