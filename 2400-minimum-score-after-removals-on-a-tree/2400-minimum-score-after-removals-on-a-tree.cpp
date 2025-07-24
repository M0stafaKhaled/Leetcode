class Solution {
public:
    int vals[1000];
    bool vist[1000];
    int parent[1001];
    int in[1000];
    int out[1000];
    int timer = 0;
    int dfs(vector<int>& nums, vector<vector<int>>& graph, int node) {
        int val = nums[node];
        vist[node] = true;
        in[node] = timer++;
        for (int i = 0; i < graph[node].size(); i++) {
            int child = graph[node][i];
            if (!vist[child]) {
                parent[child] = node;
                val = val ^ dfs(nums, graph, child);
            }
        }
        out[node] = timer++;
        return vals[node] = val;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> graph(nums.size());

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(nums, graph, 0);
        int ans = INT_MAX;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int child1 = (parent[a] == b) ? a : b;
            for (int j = i + 1; j < edges.size(); j++) {
                int c = edges[j][0];
                int d = edges[j][1];

                int child2 = (parent[c] == d) ? c : d;

                int x, y, z;

                if (in[child1] < in[child2] && out[child2] < out[child1]) {

                    x = vals[child2];
                    y = vals[child1] ^ vals[child2];
                    z = vals[0] ^ vals[child1];
                } else if (in[child2] < in[child1] &&
                           out[child1] < out[child2]) {

                    x = vals[child1];
                    y = vals[child2] ^ vals[child1];
                    z = vals[0] ^ vals[child2];
                } else {

                    x = vals[child1];
                    y = vals[child2];
                    z = vals[0] ^ x ^ y;
                }

                int m1 = min({x, y, z});
                int m2 = max({x, y, z});
                ans = min(m2 - m1, ans);
            }
        }

        return ans;
    }
};