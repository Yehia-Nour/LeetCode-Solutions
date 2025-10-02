public class Solution
{
    Dictionary<Node, Node> clones = new Dictionary<Node, Node>();

    Node Dfs(Node node)
    {
        if (node == null) return null;

        if (clones.ContainsKey(node))
            return clones[node];

        Node newNode = new Node(node.val);
        clones[node] = newNode;

        foreach (Node neighbor in node.neighbors)
        {
            newNode.neighbors.Add(Dfs(neighbor));
        }

        return newNode;
    }

    public Node CloneGraph(Node node)
    {
        return Dfs(node);
    }
}
