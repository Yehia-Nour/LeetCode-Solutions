public class Solution
{
    List<int>[] _graph;
    HashSet<(int, int)> _original;
    bool[] _visited;
    int _changes = 0;

    public int MinReorder(int n, int[][] connections)
    {
        _graph = new List<int>[n];
        for (int i = 0; i < n; i++)
            _graph[i] = new List<int>();

        _original = new HashSet<(int, int)>();

        void AddDirectedEdge(int from, int to)
        {
            _graph[from].Add(to);
            _graph[to].Add(from);
            _original.Add((from, to));
        }

        foreach (var edge in connections)
            AddDirectedEdge(edge[0], edge[1]);

        _visited = new bool[n];
        Dfs(0);

        return _changes;
    }

    void Dfs(int node)
    {
        _visited[node] = true;

        foreach (var neighbor in _graph[node])
        {
            if (_visited[neighbor]) continue;

            if (_original.Contains((node, neighbor)))
                _changes++;

            Dfs(neighbor);
        }
    }
}
