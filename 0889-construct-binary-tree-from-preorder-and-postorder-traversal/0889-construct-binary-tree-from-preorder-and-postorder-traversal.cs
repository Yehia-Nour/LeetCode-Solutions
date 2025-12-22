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
    int _preIndex = 0;
    Dictionary<int, int> _postIndexMap;
    public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder)
    {
        _postIndexMap = [];
        for (int i = 0; i < postorder.Length; i++)
            _postIndexMap[postorder[i]] = i;

        return Build(preorder, postorder, 0, postorder.Length - 1);
    }

    TreeNode Build(int[] preorder, int[] postorder, int postStart, int postEnd)
    {
        if (_preIndex >= preorder.Length || postStart > postEnd)
            return null;

        TreeNode root = new(preorder[_preIndex++]);

        if (postStart == postEnd)
            return root;

        int leftRootVal = preorder[_preIndex];
        int leftRootIndex = _postIndexMap[leftRootVal];

        root.left = Build(preorder, postorder, postStart, leftRootIndex);
        root.right = Build(preorder, postorder, leftRootIndex + 1, postEnd - 1);

        return root;
    }
}