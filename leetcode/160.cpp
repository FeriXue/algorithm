#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 暴力破解法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB, *ans = nullptr;
        while (t1) {
            while (t2) {
                if (t1 == t2) {
                    ans = t1;
                    return ans;
                }
                t2 = t2->next;
            }
            t2 = headB;
            t1 = t1->next;
        }
        return ans;
    }
};

// 方法二；
// 双指针
class Solutio {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 由题意得知，当两个链表中有一个为空时，必不相交
        if (!headA || !headB) {
            return nullptr;
        }
        // 虽然A B链表长度不相同，但是m + n == len(A + B) == len(B + A)
        //让t1指针先遍历A, 再遍历B，t1指针遍历过的总长度为 n + m
        //让t2指针先遍历B，再遍历A，t2指针遍历过的总长度也是m + n
        //假如这两个链表相交，那么无论是A + B还是B + A因为它们的总长度相等，那么必定有共同的一段后缀，此时当t1 == t2时就是它们相交的第一个节点
        //假如这两个链表不相交，那么它们就没有共同的后缀，当t1和t2的下一个节点同时为nullptr时说明没有相交
        //其实就是如果两个链表长度相同的时候直接进行判断，长度不同的时候判断它们相加的后缀是否相同
        ListNode *t1 = headA, *t2 = headB;
        while (t1 != t2) {
            if (!t1->next && !t2->next) {
                return nullptr;
            }
            if (!t1->next) {
                t1 = headB;
            } else {
                t1 = t1->next;
            }
            if (!t2->next) {
                t2 = headA;
            } else {
                t2 = t2->next;
            }
        }
        return t1;
    }
};
