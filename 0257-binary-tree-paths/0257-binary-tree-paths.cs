public class Solution
{
    List<string> res = new List<string>();

    void Paths(TreeNode root, string path)
    {
        path += root.val;

        if (root.left == null && root.right == null)
        {
            res.Add(path);
            return;
        }


        path += "->";

        if (root.left != null)
            Paths(root.left, path);
        
        if (root.right != null)
            Paths(root.right, path);
    }
    public IList<string> BinaryTreePaths(TreeNode root)
    {
        string path = "";

        Paths(root, path);

        return res;
    }
}
