#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// dfs合并二叉树；
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if (!r1) {
            return r2;
        }
        if (!r2) {
            return r1;
        }

        auto merged = new TreeNode(r1->val + r2-> val);
        merged->left = mergeTrees(r1->left, r2->left);
        merged->right = mergeTrees(r1->right, r2->right);
        return merged;
    }
};

// bfs合并二叉树
class Soluti {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if (!r1) {
            return r2;
        }
        if (!r2) {
            return r1;
        }

        auto merged = new TreeNode(r1->val + r2->val);
        queue<TreeNode *> q;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q.push(merged);
        q1.push(r1);
        q2.push(r2);
        while (!q1.empty() && !q2.empty()) {
            auto node = q.front(), node1 = q1.front(), node2 = q2.front();
            auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
            q.pop();
            q1.pop();
            q2.pop();
            if (left1 || left2) {
                if (left1 && left2) {
                    auto left = new TreeNode(left1->val + left2->val);
                    node->left = left;
                    q.push(left);
                    q1.push(left1);
                    q2.push(left2);
                } else if (left1 == nullptr) {
                    node->left = left2;
                } else if (left2 == nullptr) {
                    node->left = left1;
                }
            }
            if (right1 || right2) {
                if (right1 && right2) {
                    auto right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    q.push(right);
                    q1.push(right1);
                    q2.push(right2);
                } else if (!right1) {
                    node->right = right2;
                } else if (!right2) {
                    node->right = right1;
                }
            }
        }
        return merged;
    }
};
