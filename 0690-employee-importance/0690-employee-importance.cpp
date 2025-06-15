class Solution {
public:
    int dfs(unordered_map<int, Employee*>& graph, int id, unordered_set<int>& visited) {
        if (visited.count(id)) return 0;
        visited.insert(id);

        Employee* employee = graph[id];
        int total = employee->importance;

        for (int subId : employee->subordinates) {
            total += dfs(graph, subId, visited);
        }

        return total;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> graph;
        for (auto e : employees) {
            graph[e->id] = e;
        }

        unordered_set<int> visited;
        return dfs(graph, id, visited);
    }
};
