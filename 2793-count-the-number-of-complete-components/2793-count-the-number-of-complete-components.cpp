class Solution {
public:
    vector<bool> vist;
    vector<vector<int>> flag;
    int dfs(int node, vector<vector<int>>& graph, int f) {
        if (vist[node])
            return 0;
        int cur = 1;
        flag[f].push_back(node);
        vist[node] = 1;
        for (int i = 0; i < graph[node].size(); i++) {
            int ch = graph[node][i];
            if (!vist[ch]) {
                cur += dfs(ch, graph, f);
            }
        }
        return cur;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);
        vist = vector<bool>(n, 0);
        flag = vector<vector<int>>(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            if (vist[i])
                continue;
            int cur = dfs(i, graph, i);
            map[i] = cur;
            bool re = true;
            for (auto e : flag[i]) {
                if (graph[e].size() != cur - 1)
                    re = 0;
            }
            if (re)
                ans++;
        }

        return ans;
    }
};