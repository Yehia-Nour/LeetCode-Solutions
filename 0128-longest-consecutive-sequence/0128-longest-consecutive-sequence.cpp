class Solution {
    typedef unordered_map<int, vector<int>> GRAPH;

    void add_undirected_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int dfs(GRAPH &graph, int node, unordered_set<int> &visited) {
        visited.insert(node);

        for (int neighbour : graph[node])
            if (!visited.count(neighbour))
                return 1 + dfs(graph, neighbour, visited);
        return 1;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        if(nums_set.size() == 0) return 0; 

        GRAPH graph;
		for (int val : nums_set) {	
			if (nums_set.count(val + 1))
				add_undirected_edge(graph, val, val + 1);
		}

		int mx_cc_size = 1; 
		unordered_set<int> visited;

		for (auto &node_adj : graph) {
			if (!visited.count(node_adj.first) && node_adj.second.size() == 1) {
				int cc_size = dfs(graph, node_adj.first, visited);
				mx_cc_size = max(mx_cc_size, cc_size);
			}
		}
		return mx_cc_size;
    }
};