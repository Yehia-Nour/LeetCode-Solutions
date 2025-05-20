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
    vector<vector<int>> mainVec;

    void helper(TreeNode *root, int targetSum, vector<int> vec) {
        if (!root || targetSum < 0) return;
        targetSum -= root->val;
        vec.push_back(root->val);
        
        if (targetSum == 0) mainVec.push_back(vec);
        

        vector<int> l = vec;
        vector<int> r = vec;

        helper(root->left, targetSum, l);
        helper(root->right, targetSum, r);
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        if (!root || targetSum == root->val) {
            return mainVec;
        }
        helper(root, targetSum, vec);

        return mainVec;
    }
};