#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int now = 0, depth = 0;
    // 回溯加剪枝
    void dfs(TreeNode *root)
    {
        if (!root) {
            return;
        }
        ++now;
        dfs(root->left);
        depth = max(now, depth);
        dfs(root->right);
        depth = max(now, depth);
        --now;
    }

    int maxDepth(TreeNode* root) {
        dfs(root);
        return depth;
    }
};
