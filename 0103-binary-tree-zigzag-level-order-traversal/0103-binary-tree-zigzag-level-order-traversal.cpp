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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {}; // إذا كانت الشجرة فارغة، نرجع مصفوفة فارغة
        
        deque<TreeNode*> nodes_deque;
        nodes_deque.push_front(root);

        vector<vector<int>> vec;
        int level = 0;

        while (!nodes_deque.empty()) 
        {
            int size = nodes_deque.size();
            
            if (vec.size() <= level) vec.push_back({});

            if (level % 2 == 0) 
            {
                while (size--) 
                {
                    TreeNode* cur = nodes_deque.front();
                    nodes_deque.pop_front();

                    vec[level].push_back(cur->val);

                    if (cur->left) nodes_deque.push_back(cur->left); 
                    if (cur->right) nodes_deque.push_back(cur->right);
                }
            } 
            else 
            {
                while (size--) 
                {
                    TreeNode* cur = nodes_deque.back();
                    nodes_deque.pop_back();
                    
                    vec[level].push_back(cur->val);

                    if (cur->right) nodes_deque.push_front(cur->right);
                    if (cur->left) nodes_deque.push_front(cur->left);
                }
            }
            level++;
        }

        return vec;
    }
};