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
    void PreOrder(TreeNode* root, vector<int> &vec)
    {
        if(root == NULL) return;

        vec.push_back(root->val);
        PreOrder(root->left, vec);
        PreOrder(root->right, vec);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        PreOrder(root, res);
        return res;
    }
};