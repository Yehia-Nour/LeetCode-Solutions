class Solution {
public:
    int checkDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = checkDepth(root->left);
        if (left == -1) return -1;

        int right = checkDepth(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkDepth(root) != -1;
    }
};
