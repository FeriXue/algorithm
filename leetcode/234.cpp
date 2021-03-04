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
    ListNode *reverse(ListNode *head) 
    {
        ListNode *curr = head;
        ListNode *pre = nullptr;

        while (curr) {
            ListNode *temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }

    ListNode *qsmiddle(ListNode *head) 
    {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        ListNode *middle = qsmiddle(head);
        ListNode *start = reverse(middle->next);
        bool flag = 1;
        ListNode *t1 = head, *t2 = start;
        while (flag && t2 != nullptr) {
            if (t1->val != t2->val) {
                flag = 0;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        

        middle->next = reverse(start);
        return flag;
    }
};

