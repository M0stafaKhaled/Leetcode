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

        bool cut(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py)
                return false;

            return 1;
        }
    };
    bool equationsPossible(vector<string>& equations) {

        DSU dsu(26);
        vector<pair<char, char>> pr;
        for (int i = 0; i < equations.size(); i++) {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if (equations[i][1] == '!') {
                pr.push_back({equations[i][0], equations[i][3]});
            } else {

                dsu.con(a, b);
            }
        }

        for (auto e : pr) {
            int a = e.first - 'a';
            int b = e.second - 'a';
            if (!dsu.cut(a, b))
                return false;
        }

        return 1;
    }
};