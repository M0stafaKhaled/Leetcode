class Solution {
public:
    class DSU {
    public:
        vector<int> pr;
        vector<int> size;
        DSU(int n) {
            pr.resize(n);
            size = vector<int>(n, 1);

            for (int i = 0; i < n; i++)
                pr[i] = i;
        }

        int find(int x) {
            if (x == pr[x])
                return x;

            return pr[x] = find(pr[x]);
        }

        void con(int x, int y) {
            int px = find(x);
            int py = find(y);

            if (px == py)
                return;
            if (size[px] < size[py]) {
                swap(px, py);
            }
            pr[py] = px;
            size[px]+=size[py];

        }
    };
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        DSU dsu(n);

        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            dsu.con(x, y);
        }
        cout << dsu.find(source) << " " << dsu.find(destination);
        return dsu.find(source) == dsu.find(destination);
    }
};