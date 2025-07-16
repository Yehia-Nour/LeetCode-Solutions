using GRAPH = System.Collections.Generic.List<System.Collections.Generic.List<int>>;
public class Solution
{
    private void AddDirectedEdge(GRAPH graph, int from, int to)
    {
        graph[from].Add(to);
    }

    public int[] FindOrder(int numCourses, int[][] prerequisites)
    {
        GRAPH graph = new GRAPH();
        for (int i = 0; i < numCourses; ++i)
            graph.Add(new List<int>());

        foreach (var pre in prerequisites)
        {
            AddDirectedEdge(graph, pre[1], pre[0]);
        }

        int[] indegree = new int[numCourses];
        for (int i = 0; i < numCourses; ++i)
            foreach (int j in graph[i])
                indegree[j]++;

        Queue<int> ready = new Queue<int>();
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                ready.Enqueue(i);

        List<int> res = new List<int>();

        while (ready.Count > 0)
        {
            int i = ready.Dequeue();
            res.Add(i);

            foreach (int j in graph[i])
                if (--indegree[j] == 0)
                    ready.Enqueue(j);
        }

        if (res.Count < numCourses)
            return new int[0];

        return res.ToArray();
    }
}