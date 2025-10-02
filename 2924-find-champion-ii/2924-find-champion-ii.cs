public class Solution
{
    List<int>[] _graph;
    int[] _inDegree;

    void AddDirectedEdge(int from, int to)
    {
        _graph[from].Add(to);
        _inDegree[to]++;
    }

    public int FindChampion(int n, int[][] edges)
    {
        _graph = new List<int>[n];
        for (int i = 0; i < n; i++)
            _graph[i] = new List<int>();

        _inDegree = new int[n];

        for (int i = 0; i < edges.Length; i++)
            AddDirectedEdge(edges[i][0], edges[i][1]);

        int champion = -1;

        for (int i = 0; i < n; i++)
        {
            if (_inDegree[i] == 0)
            {
                if (champion != -1)
                    return -1;
                champion = i;
            }
        }

        return champion;
    }
}