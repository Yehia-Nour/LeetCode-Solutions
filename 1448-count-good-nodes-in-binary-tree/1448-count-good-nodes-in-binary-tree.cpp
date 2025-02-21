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
        int dummy(TreeNode* root) {
        if (!root) return 0; 
        int i = 0;

        if(root->left && root->left->val >= root->val) ++i;
        if(root->right && root->right->val >= root->val) ++i;

        int l = dummy(root->left);
        int r = dummy(root->right);

        return i + l + r;
    }

    int goodNodes(TreeNode* root) {
        return dummy(root) + 1;
    }
};