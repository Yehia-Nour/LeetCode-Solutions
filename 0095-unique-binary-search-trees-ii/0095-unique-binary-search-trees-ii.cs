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
    Dictionary<(int, int), IList<TreeNode>> _memo = new();
    IList<TreeNode> Build(int start, int end)
    {
        if (start > end)
            return new List<TreeNode> { null };

        var key = (start, end);
        if (_memo.ContainsKey(key))
            return _memo[key];

        var result = new List<TreeNode>();

        for (int rootVal = start; rootVal <= end; rootVal++)
        {
            var leftTrees = Build(start, rootVal - 1);
            var rightTrees = Build(rootVal + 1, end);

            foreach (var left in leftTrees)
            {
                foreach (var right in rightTrees)
                {
                    var root = new TreeNode(rootVal, left, right);
                    result.Add(root);
                }
            }
        }

        _memo[key] = result;
        return result;
    }

    public IList<TreeNode> GenerateTrees(int n)
    {
        if (n == 0) return [];
        return Build(1, n);
    }
}
