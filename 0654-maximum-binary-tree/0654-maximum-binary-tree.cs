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
    int[] _nums;
    int _n;
    TreeNode Build(int start, int end)
    {
        if (start > end)
            return null;

        int max = _nums[start], mid = start;

        for (int i = start + 1; i <= end; i++)
        {
            if (_nums[i] > max)
            {
                max = _nums[i];
                mid = i;
            }
        }

        var root = new TreeNode(max);

        root.left = Build(start, mid - 1);
        root.right = Build(mid + 1, end);

        return root;
    }
    public TreeNode ConstructMaximumBinaryTree(int[] nums)
    {
        _nums = nums;
        _n = _nums.Length;

        return Build(0, _n - 1);
    }
}