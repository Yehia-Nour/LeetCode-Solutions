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
    int _postorderIndex;
    int[] _postorder;
    Dictionary<int, int> _inorderMap;

    TreeNode Build(int left, int right)
    {
        if (left > right)
            return null;

        int rooVal = _postorder[_postorderIndex--];
        var root = new TreeNode(rooVal);

        int mid = _inorderMap[rooVal];

        root.right = Build(mid + 1, right);
        root.left = Build(left, mid - 1);

        return root;
    }
    public TreeNode BuildTree(int[] inorder, int[] postorder)
    {
        int n = inorder.Length;
        _postorder = postorder; 
        _postorderIndex = n - 1;
        _inorderMap = [];

        for (int i = 0; i < n; i++)
            _inorderMap[inorder[i]] = i;

        return Build(0, n - 1);
    }
}