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
class Solution
{
    void InsertTreeNodeToStack(TreeNode root, Stack<TreeNode> stc)
    {
        if (root is null)
            return;

        stc.Push(root);
        InsertTreeNodeToStack(root.left, stc);
        InsertTreeNodeToStack(root.right, stc);
    }
    public void Flatten(TreeNode root)
    {
        if (root is null)
            return;
        Stack<TreeNode> stc = new();
        InsertTreeNodeToStack(root, stc);

        TreeNode cur = stc.Pop();

        while (stc.Count > 0)
        {
            TreeNode temp = stc.Pop();
            temp.left = null!;
            temp.right = cur;
            cur = temp;
        }
    }
}