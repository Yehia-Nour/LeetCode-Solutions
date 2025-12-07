/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    int _preorderIndex;
    int[] _preorder;
    Dictionary<int, int>  _inorderMap;

    TreeNode Build(int left, int right)
    {
        if (left > right)
            return null;

        int rooVal = _preorder[_preorderIndex++];
        var root = new TreeNode(rooVal);
        
        int mid = _inorderMap[rooVal];

        root.left = Build(left, mid - 1);
        root.right = Build(mid + 1, right);

        return root;
    }
    public TreeNode BuildTree(int[] preorder, int[] inorder)
    {
        _preorder = preorder;
        _inorderMap = [];
        _preorderIndex = 0;
        int n = inorder.Length;

        for(int i = 0; i < n; i++)
            _inorderMap[inorder[i]] = i;

        return Build(0, n - 1);
    }
}