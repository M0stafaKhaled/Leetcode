class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> size;

        DSU(int n) {
            parent.resize(n + 1);
            size.assign(n + 1, 1);

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int node) {
            if (parent[node] == node) {
                return node;
            }

            return parent[node] = find(parent[node]);
        }

        void unite(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if (pa == pb) {
                return;
            }

            if (size[pa] < size[pb]) {
                swap(pa, pb);
            }

            parent[pb] = pa;
            size[pa] += size[pb];
        }
    };

    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];

            dsu.unite(u, v);
        }

        int componentOfOne = dsu.find(1);
        int ans = INT_MAX;

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];

            if (dsu.find(u) == componentOfOne) {
                ans = min(ans, dist);
            }
        }

        return ans;
    }
};