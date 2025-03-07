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
    int runningSum = 0;

    void bstToGst(TreeNode* root) {
        if (!root) return;

        bstToGst(root->right);

        runningSum += root->val;
        root->val = runningSum;

        bstToGst(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        bstToGst(root);
        return root;
    }
};