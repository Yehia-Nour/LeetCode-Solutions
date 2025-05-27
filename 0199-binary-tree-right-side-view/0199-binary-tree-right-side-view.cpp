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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while (!dq.empty()) {
            int size = dq.size();

            res.push_back(dq.back()->val);
            while (size--) {
                TreeNode *cur = dq.front();
                dq.pop_front();

                if (cur->left) dq.push_back(cur->left);
                if (cur->right) dq.push_back(cur->right);
            }
        }

        return res;
    }
};