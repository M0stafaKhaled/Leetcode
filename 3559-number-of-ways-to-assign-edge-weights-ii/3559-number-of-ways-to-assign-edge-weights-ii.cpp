class Solution {
public:
    static constexpr int LOG = 18;
    int lca(int u, int v) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }

        int diff = depth[v] - depth[u];

        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                v = up[v][i];
            }
        }

        if (u == v)
            return u;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }
    vector<int> parent;
    vector<vector<int>> up;
    vector<vector<int>> graph;
    vector<int> depth;
    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child == parent) {
                continue;
            }

            depth[child] = depth[node] + 1;
            up[child][0] = node;

            for (int j = 1; j < LOG; j++) {
                up[child][j] = up[up[child][j - 1]][j - 1];
            }

            dfs(child, node);
        }
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 2;
        graph.resize(n);
        up.assign(n + 1, vector<int>(LOG));
        depth.resize(n);
        parent.resize(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int j = 0; j < LOG; j++) {
            up[1][j] = 1;
        }
        vector<int> pow2(n + 1);
        pow2[0] = 1;
        int mode = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2LL) % mode;
        }
        dfs(1, 1);
        vector<int> ans;
        // int mode = 1e9 + 7;
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            int lc = depth[(lca(u, v))];
            int first = depth[u] - lc;
            int second = depth[v] - lc;
            int cur = first + second;
            if (cur == 0) {
                ans.push_back(0);
            } else {

                ans.push_back(pow2[cur - 1]);
            }
        }

        return ans;
    }
};