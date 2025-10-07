public class Solution
{
    List<int>[] _graph;
    int _n;
    int _count = 0;

    void AddDirectedEdge(int from, int to)
    {
        _graph[from].Add(to);
    }

    void Dfs(int node, List<int>[] grid, bool[] visited)
    {
        visited[node] = true;

        foreach (int neighbor in grid[node])
        {
            if (!visited[neighbor])
                Dfs(neighbor, grid, visited);
        }
    }

    public int FindCircleNum(int[][] isConnected)
    {
        _n = isConnected.Length;
        _graph = new List<int>[_n];
        for (int i = 0; i < _n; i++)
            _graph[i] = new List<int>();

        for (int i = 0; i < _n; i++)
        {
            for (int j = 0; j < _n; j++)
                if (isConnected[i][j] == 1)
                    AddDirectedEdge(i, j);
        }

        bool[] visited = new bool[_n];

        for (int i = 0; i < _n; i++)
        {
            if (!visited[i])
            {
                _count++;
                Dfs(i, _graph, visited);
            }
        }

        return _count;
    }
}