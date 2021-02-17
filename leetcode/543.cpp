#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int depth(TreeNode *root, int &ans) 
    {
        if (!root) {
            return 0;
        }

        int ll = depth(root->left, ans); // 以root为根节点的左子树的高度
        int rr = depth(root->right, ans); // 以root为根节点的右子树的高度
        ans = max(ans, ll + rr + 1); // 此处ans代表以root为根节点的最长路径中的节点数即为左子树的深度加右子树的深度加一
        return max(ll, rr) + 1; // 返回以root为根节点的子树的高度
    }

    // 二叉树的先根遍历：根，左，右；
    // 求二叉树的直径问题可以转换为求二叉树中的最长路径，路径的长度等于经过的节点数减一，最长路径经过的节点等于根节点的左子树的深度加根节点的右子树的深度加一（加上根节点），所以这个问题我们只需要求出左右子树的深度之和加一再减一即可。
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        depth(root, ans);
        return ans - 1; // 求路径长度，所以用路径中的节点数减一；
    }
};
