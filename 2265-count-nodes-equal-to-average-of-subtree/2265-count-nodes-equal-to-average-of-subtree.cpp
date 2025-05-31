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
    int res = 0;
    pair<int, int> helper(TreeNode* root) {
        if (!root) return {0, 0};

        auto l = helper(root->left);
        auto r = helper(root->right);

        int sum = l.first + r.first + root->val;
        int elments = l.second + r.second + 1;

        if (sum / elments == root->val) res++;

        return {sum, elments};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return res;
    }
};