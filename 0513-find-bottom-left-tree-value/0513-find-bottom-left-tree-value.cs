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
    int MaxLevel(TreeNode root)
    {
        if (root == null) return 0;

        int left = MaxLevel(root.left);
        int right = MaxLevel(root.right);

        return Math.Max(left, right) + 1;
    }

    public int FindBottomLeftValue(TreeNode root)
    {
        int maxLevel = MaxLevel(root) - 1;

        Queue<TreeNode> queue = [];
        queue.Enqueue(root);

        int level = 0;

        while (queue.Count > 0)
        {
            int len = queue.Count;

            for (int i = 0; i < len; i++)
            {
                TreeNode curr = queue.Dequeue();

                if (level == maxLevel && i == 0)
                    return curr.val;

                if (curr.left != null)
                    queue.Enqueue(curr.left);

                if (curr.right != null)
                    queue.Enqueue(curr.right);
            }

            level++;
        }

        return 0; 
    }
}
