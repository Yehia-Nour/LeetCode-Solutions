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
    string toStr(int n) {
        ostringstream oss;
        oss << n;
        return oss.str();
    }
	string _parenthesize_canonical(TreeNode *root) {
		if (!root)
			return "()";

		string repr = "(" + toStr(root->val);

		vector<string> v;

		if (left)
			v.push_back(_parenthesize_canonical(root->left));
		else
			v.push_back("()");

		if (right)
			v.push_back(_parenthesize_canonical(root->right));
		else
			v.push_back("()");

		sort(v.begin(), v.end());
		for (int i = 0; i < (int) v.size(); ++i)
			repr += v[i];

		repr += ")";

		return repr;
	}
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        string str_root1 = _parenthesize_canonical(root1);
        string str_root2 = _parenthesize_canonical(root2);

        return str_root1 == str_root2;
    }
};