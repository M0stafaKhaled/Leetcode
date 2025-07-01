class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int>& vist, int i, int color) {
        vist[i] = color;

        for (auto e : graph[i]) {
            if (vist[e] == vist[i])
                return false;
            if (vist[e] == -1) {
                if (!dfs(graph, vist, e, color ^ 1))
                    return 0;
            }
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, -1);

        vector<vector<int>> graph(n + 1);
        vector<int> vist(n + 1, -1);
        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (vist[i] == -1) {
                if (!dfs(graph, vist, i, 0))
                    return false;
            }
        }

        return true;
    }
};