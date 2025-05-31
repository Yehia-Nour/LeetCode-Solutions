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
private:
    pair<int, int> helper(TreeNode* root, int& res) {
        if (!root) return {0, 0};
        auto l = helper(root->left, res);
        auto r = helper(root->right, res);
        int sum = l.first + r.first + root->val;
        int elements = l.second + r.second + 1;
        if (sum / elements == root->val) res++;
        return {sum, elements};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};
