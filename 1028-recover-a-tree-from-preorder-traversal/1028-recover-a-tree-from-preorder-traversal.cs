public class Solution
{
    public TreeNode RecoverFromPreorder(string traversal)
    {
        List<(int depth, int value)> nodes = [];

        int i = 0;
        while (i < traversal.Length)
        {
            int depth = 0;
            while (i < traversal.Length && traversal[i] == '-')
            {
                depth++;
                i++;
            }

            int value = 0;
            while (i < traversal.Length && char.IsDigit(traversal[i]))
            {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            nodes.Add((depth, value));
        }

        Stack<TreeNode> st = [];
        TreeNode root = null;

        foreach (var nodeInfo in nodes)
        {
            int depth = nodeInfo.depth;
            int value = nodeInfo.value;

            TreeNode newNode = new(value);

            if (depth == 0)
            {
                root = newNode;
                st.Push(root);
            }
            else
            {
                while (st.Count > depth)
                    st.Pop();

                TreeNode parent = st.Peek();

                if (parent.left == null)
                    parent.left = newNode;
                else
                    parent.right = newNode;

                st.Push(newNode);
            }
        }

        return root;
    }
}
