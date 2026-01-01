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
    int _maxSum = int.MinValue;
    public int MaxPathSum(TreeNode root)
    {
        DFS(root);

        return _maxSum;
    }

    int DFS(TreeNode root)
    {
        if (root is null)
            return 0;

        int left = int.Max(0, DFS(root.left));
        int right = int.Max(0, DFS(root.right));

        int currentPath = left + right + root.val;

        _maxSum = int.Max(currentPath, _maxSum);

        return root.val + int.Max(left, right);
    }
}