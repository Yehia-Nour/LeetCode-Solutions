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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> que;
        que.push(root);
        int level = 0;

        while (!que.empty()) {
            int size = que.size();
            vector<TreeNode*> vec;

            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();

                if (level % 2 == 1) {
                    vec.push_back(cur);
                }

                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }

            if (level % 2 == 1) {
                int l = 0, r = vec.size() - 1;
                while (l < r) {
                    swap(vec[l]->val, vec[r]->val); 
                    l++;
                    r--;
                }
            }

            level++;
        }

        return root;
    }
};