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
            size[px] += size[py];
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {

        DSU dsu(n);
        int k = 0;
        for (int i = 0; i < connections.size(); i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            if (dsu.find(a) == dsu.find(b)) {
                k++;
            } else
                dsu.con(a, connections[i][1]);
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (dsu.find(i) != dsu.find(i + 1)) {
                if (k == 0)
                    return -1;
                ans++;
                k--;
                dsu.con(i, i + 1);
            }
        }
        return ans;
    }
};