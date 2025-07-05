class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor])
                dfs(neighbor, graph, visited, component);
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        vector<vector<int>> graph(n);
        for (auto& swap : allowedSwaps) {
            int u = swap[0], v = swap[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int totalDiff = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            vector<int> component;
            dfs(i, graph, visited, component);

            unordered_map<int, int> freqSource, freqTarget;
            for (int index : component) {
                freqSource[source[index]]++;
                freqTarget[target[index]]++;
            }

            for (auto& [val, count] : freqTarget) {
                int match = min(count, freqSource[val]);
                totalDiff += (count - match);
            }
        }

        return totalDiff;
    }
};