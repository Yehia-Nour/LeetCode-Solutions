/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, row + 1, col - 1});
            if (node->right)
                q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> result;

        for (auto& col : nodes) {
            vector<int> colValues;
            for (auto& row : col.second) {
                colValues.insert(colValues.end(), row.second.begin(),
                                 row.second.end());
            }
            result.push_back(colValues);
        }

        return result;
    }
};