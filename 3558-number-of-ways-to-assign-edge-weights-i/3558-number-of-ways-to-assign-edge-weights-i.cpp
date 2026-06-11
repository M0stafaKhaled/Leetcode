class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long modPow(long long base, int exponent) {
        long long result = 1;

        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exponent >>= 1;
        }

        return result;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = static_cast<int>(edges.size()) + 1;

        vector<vector<int>> graph(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int neighbor : graph[node]) {
                if (visited[neighbor]) {
                    continue;
                }

                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
            }
        }

        return static_cast<int>(modPow(2, maxDepth - 1));
    }
};