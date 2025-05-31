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
    void insert(TreeNode *root, int value) {
        if (root->val > value) {
            if (root->left) insert(root->left, value);
            else root->left = new TreeNode(value);
        } else {
            if (root->right) insert(root->right, value);
            else root->right = new TreeNode(value);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {
            insert(root, preorder[i]);
        }

        return root;
    }
};