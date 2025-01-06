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
    void InOrder(TreeNode* r, vector<int> &vec)
    {
        if(r == NULL) return;

        InOrder(r->left, vec);
        vec.push_back(r->val);
        InOrder(r->right, vec);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        InOrder(root, result);
        return result;
    }
};