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
    public TreeNode PruneTree(TreeNode root)
    {
        if (root is null)
            return null;

        root.left = PruneTree(root.left);
        root.right = PruneTree(root.right);

        if (root.val == 0 && root.left is null && root.right is null)
            return null;

        return root;
    }
}