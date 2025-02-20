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
	int findNodeDepth(TreeNode *root, int value, int curDepth = 0) {
		if (!root)
			return 0;

		if (root->val == value)
			return curDepth;

		int leftDepth = findNodeDepth(root->left, value, curDepth + 1);
		if (leftDepth != 0)
			return leftDepth;

		return findNodeDepth(root->right, value, curDepth + 1);
	}

	TreeNode* findParentNode(TreeNode *root, int value, TreeNode *parent = nullptr) {
		if (!root)
			return nullptr;

		if(root->val == value)
			return parent;

		TreeNode *leftParent = findParentNode(root->left, value, root);
		if (leftParent)
			return leftParent;

		return findParentNode(root->right, value, root);
	}
	bool isCousins(TreeNode *root, int x, int y) {
		if (findNodeDepth(root, x) != findNodeDepth(root, y))
			return false;

		if (findParentNode(root, x) == findParentNode(root, y))
			return false;
		return true;
	}
};