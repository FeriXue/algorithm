#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool check(TreeNode *p, TreeNode *q) 
    {
        if (!p && !q) {
            return 1;
        }
        if (!p || !q) {
            return 0;
        }
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

class Solution2 {
public:
    bool check(TreeNode *l, TreeNode *r)
    {
        queue<TreeNode *> q;
        q.push(l);
        q.push(r);
        while (!q.empty()) {
            TreeNode *u = q.front();
            q.pop();
            TreeNode *v = q.front();
            q.pop();
            if (!u && !v) {
                // 两个指针同时为空
                continue;
            }
            if ((!u || !v) || (u->val != v->val)) {
                return 0;
            }
            q.push(u->left);
            q.push(v->right);
            q.push(u->right);
            q.push(v->left);
        }
        return 1;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

