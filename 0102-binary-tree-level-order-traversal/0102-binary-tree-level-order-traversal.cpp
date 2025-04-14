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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (!root) return vec;

        queue<TreeNode*> nodes_queue;
        nodes_queue.push(root);

        while (!nodes_queue.empty()) {
            int level_size = nodes_queue.size();
            vector<int> level_vals;

            for (int i = 0; i < level_size; ++i) {
                TreeNode* cur = nodes_queue.front();
                nodes_queue.pop();
                level_vals.push_back(cur->val);

                if (cur->left) nodes_queue.push(cur->left);
                if (cur->right) nodes_queue.push(cur->right);
            }

            vec.push_back(level_vals);
        }

        return vec;
    }
};