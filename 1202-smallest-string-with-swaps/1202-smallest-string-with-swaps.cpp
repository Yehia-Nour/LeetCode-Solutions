class Solution {
    typedef vector<vector<int>> GRAPH;

    void add_undirected_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    void dfs(GRAPH &graph, int node, vector<bool> &visited, vector<int> &cc_nodes) {
        visited[node] = true;
        cc_nodes.push_back(node);

        for (int neighbour : graph[node]) {
            if (!visited[neighbour])
                dfs(graph, neighbour, visited, cc_nodes);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int nodes = s.length();
        GRAPH graph(nodes);
        for (int i = 0; i < pairs.size(); ++i)
			add_undirected_edge(graph, pairs[i][0], pairs[i][1]);

        vector<bool> visisted(nodes);

        for (int i = 0; i < nodes; i++) {
            if (!visisted[i]) {
                vector<int> cc_nodes;
                dfs(graph, i, visisted, cc_nodes);

                string cc_letters;
                
                for (int node : cc_nodes)
                    cc_letters += s[node];

                sort(cc_nodes.begin(), cc_nodes.end());
                sort(cc_letters.begin(), cc_letters.end());

                for (int j = 0; j < cc_nodes.size(); j++)
                    s[cc_nodes[j]] = cc_letters[j];
            }
        }

        return s;
    }
};