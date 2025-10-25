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
    public int DeepestLeavesSum(TreeNode root)
    {
        if (root == null)
            return 0;

        Queue<TreeNode> queue = [];
        queue.Enqueue(root);

        int levelSum = 0;
        while (queue.Count > 0)
        {
            int size = queue.Count;
            levelSum = 0; 
            for (int i = 0; i < size; i++)
            {
                TreeNode node = queue.Dequeue();
                levelSum += node.val;

                if (node.left != null)
                    queue.Enqueue(node.left);

                if (node.right != null)
                    queue.Enqueue(node.right);
            }
        }

        return levelSum;
    }
}