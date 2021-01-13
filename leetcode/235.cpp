#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void search(TreeNode *root, TreeNode *node, stack<TreeNode*> &stk) {
        stk.push(root);
        if (node->val == root->val) {
            return;
        }
        //stk.push(root);
        if (node->val < root->val) {
            search(root->left, node, stk);
        } else {
            search(root->right, node, stk);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        stack<TreeNode*> fp, fq;
        search(root, p, fp);
        search(root, q, fq);
        if(fp.size() >= fq.size()) {
            int t = fp.size() - fq.size();
            while (t --) {
                fp.pop();
            }
            while (!fp.empty()) {
                auto a = fp.top(), b = fq.top();
                fp.pop();
                fq.pop();
                if (a == b) {
                    return a;
                }
            }
        } else {
            int t = fq.size() - fp.size();
            while (t --) {
                fq.pop();
            }
            while (!fp.empty()) {
                auto a = fp.top(), b = fq.top();
                fp.pop();
                fq.pop();
                if (a == b) {
                    return a;
                }
            }
        }
        return root;
    }
};
