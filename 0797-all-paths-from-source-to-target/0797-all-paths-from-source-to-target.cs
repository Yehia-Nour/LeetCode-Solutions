public class Solution
{
    IList<IList<int>> _res = new List<IList<int>>();
    int _target;
    void AddEdge(List<int>[] graph, int from, int to)
      => graph[from].Add(to);

    void DFS(List<int>[] graph, int node, bool[] visited, List<int> path)
    {
        visited[node] = true;
        path.Add(node);

        if (node == _target)
            _res.Add(new List<int>(path));

        foreach (var neighbor in graph[node])
            DFS(graph, neighbor, visited, path);

        visited[node] = false;
        path.RemoveAt(path.Count - 1);
    }

    public IList<IList<int>> AllPathsSourceTarget(int[][] graph)
    {
        _target = graph.Length - 1;

        List<int>[] directedGraph = new List<int>[graph.Length];

        for (int i = 0; i < graph.Length; i++)
            directedGraph[i] = new List<int>();

        for (int i = 0; i < graph.Length - 1; i++)
            for (int j = 0; j < graph[i].Length; j++)
                AddEdge(directedGraph, i, graph[i][j]);

        bool[] visited = new bool[graph.Length];

        DFS(directedGraph, 0, visited, new List<int>());

        return _res;
    }
}