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
class BSTIterator {
public:
    queue<TreeNode*> que;
    BSTIterator(TreeNode* root) {
        initializes(root);
    }
    void initializes(TreeNode* root) {
        if (!root) return;
        initializes(root->left);
        que.push(root);
        initializes(root->right);
    }
    int next() {
        int res = que.front()->val;
        que.pop();
        return res;
    }
    
    bool hasNext() {
        return !que.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */