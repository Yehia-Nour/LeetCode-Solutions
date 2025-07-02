typedef unordered_map<int, vector<int>> GRAPH;

class Solution {
    void add_undirected_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    void dfs(GRAPH &graph, int node, unordered_set<int> &visited, vector<int> &cc_nodes) {
        visited.insert(node);
        cc_nodes.push_back(node);

        for (int neighbour : graph[node]) {
            if (!visited.count(neighbour))
                dfs(graph, neighbour, visited, cc_nodes);
        }
    }
public:
	vector<int> restoreArray(vector<vector<int>> &pairs) {
		GRAPH graph;

		for (auto &pair : pairs)
			add_undirected_edge(graph, pair[0], pair[1]);

		unordered_set<int> visited;
		vector<int> cc_nodes;

		for (auto &node_adj : graph) {
			if (node_adj.second.size() == 1) {
				dfs(graph, node_adj.first, visited, cc_nodes);
				break;
			}
		}
		return cc_nodes;
	}
};