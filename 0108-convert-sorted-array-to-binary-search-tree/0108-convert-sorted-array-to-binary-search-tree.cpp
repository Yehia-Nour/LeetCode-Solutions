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
    TreeNode* sortedArrayToBST(vector<int>& values, int start, int end) {
    	if (start > end)
    		return nullptr;

    	int mid = (start + end) / 2;
    	TreeNode *root = new TreeNode(values[mid]);
    	root->left = sortedArrayToBST(values, start, mid - 1);
    	root->right = sortedArrayToBST(values, mid + 1, end);

    	return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return sortedArrayToBST(nums, 0, (int) nums.size() - 1);
    }
};