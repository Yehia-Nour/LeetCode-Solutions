/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root, int &res) {
    if (root == nullptr)
    return 0;

    int lDepth = maxDepth(root->left, res);
    int rDepth = maxDepth(root->right, res);
    res = max(res, lDepth + rDepth);

    return max(lDepth, rDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        maxDepth(root, res);

        return res;
    }
};