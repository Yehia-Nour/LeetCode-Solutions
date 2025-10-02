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
    int MinSwapsToSort(List<int> arrList)
    {
        int n = arrList.Count;
        if (n <= 1) return 0;

        var arr = new Tuple<int, int>[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = Tuple.Create(arrList[i], i);
        }

        Array.Sort(arr, (a, b) => a.Item1.CompareTo(b.Item1));

        bool[] visited = new bool[n];
        int swaps = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j])
            {
                visited[j] = true;
                j = arr[j].Item2;
                cycleSize++;
            }

            if (cycleSize > 1)
            {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }

    public int MinimumOperations(TreeNode root)
    {
        if (root == null) return 0;

        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        int totalSwaps = 0;

        while (q.Count > 0)
        {
            int levelSize = q.Count;
            List<int> vals = new List<int>(levelSize);

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode node = q.Dequeue();
                vals.Add(node.val);
                if (node.left != null) q.Enqueue(node.left);
                if (node.right != null) q.Enqueue(node.right);
            }

            totalSwaps += MinSwapsToSort(vals);
        }

        return totalSwaps;
    }

}
