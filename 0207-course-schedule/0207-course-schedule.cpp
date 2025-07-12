class Solution {
    typedef vector<vector<int>> GRAPH;

    void add_directed_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        GRAPH graph(numCourses);
        for (auto& pre : prerequisites) {
            add_directed_edge(graph, pre[1], pre[0]);
        }

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            for (int j : graph[i])
                indegree[j]++;

        queue<int> ready;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                ready.push(i);

        int count = 0;
        while (!ready.empty()) {
            int i = ready.front();
            ready.pop();
            count++;

            for (int j : graph[i])
                if (--indegree[j] == 0)
                    ready.push(j);
        }

        return count == numCourses;
    }
};
