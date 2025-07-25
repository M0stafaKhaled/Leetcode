class Solution {
public:
    class DSU {
        unordered_map<int, int> parent;

    public:
        int find(int x) {
            if (!parent.count(x))
                parent[x] = x;
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) { parent[find(x)] = find(y); }

        int count_unique_roots() {
            unordered_set<int> roots;
            for (auto [x, p] : parent)
                roots.insert(find(x));
            return roots.size();
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        int OFFSET = 10001;

        for (auto& stone : stones) {
            int x = stone[0];
            int y = stone[1] + OFFSET;
            dsu.unite(x, y);
        }

        int num_components = dsu.count_unique_roots();
        return stones.size() - num_components;
    }
};