class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vist;
    bool dfs(int node, int de) {
        vist[node] = true;

        for (auto ch : graph[node]) {
            if (ch == de)
                return true;
            if (vist[ch])
                continue;
            if (dfs(ch, de))
                return 1;
        }

        return 0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        if (source == destination)
            return 1;
        vist.assign(n, 0);

        graph.assign(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(source, destination);
    }
};