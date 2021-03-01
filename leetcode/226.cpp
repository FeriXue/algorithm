#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 翻转二叉树
class Solution {
public:
    // 二叉树的层序遍历，交换左右指针即可
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            auto lf = now->left, rg = now->right;
            if (lf && rg) {
                now->left = rg;
                now->right = lf;
                q.push(now->left);
                q.push(now->right);
            } else if (!lf && rg) {
                now->left = rg;
                now->right = nullptr;
                q.push(now->left);
            } else if (!rg && lf) {
                now->right = lf;
                now->left = nullptr;
                q.push(now->right);
            }
        }
        return root;
    }
};
