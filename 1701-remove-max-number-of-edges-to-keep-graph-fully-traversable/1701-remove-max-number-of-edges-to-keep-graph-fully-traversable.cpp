class Solution {
public:
    class Dsu {
    public:
        vector<int> arr;
        Dsu(int n) {
            arr = vector<int>(n);
            for (int i = 1; i < n; i++) {
                arr[i] = i;
            }
        }

        int find(int x) {
            if (arr[x] == x)
                return x;

            return arr[x] = find(arr[x]);
        }

        void con(int x, int y) {
            int dx = find(x);
            int dy = find(y);
            if (dx == dy)
                return;
            arr[dy] = dx;
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Dsu dsu1(n + 1);
        Dsu dsu2(n + 1);
        int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            if (a == 3) {
                if (dsu1.find(c) == dsu1.find(b) &&
                    dsu2.find(c) == dsu2.find(b))
                    ans++;
                else {
                    dsu1.con(c, b);
                    dsu2.con(c, b);
                }
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            if (a == 3)
                continue;

            if (dsu1.find(c) == dsu1.find(b) && a == 1) {

                ans++;
            } else {
                if (a == 1) {
                    dsu1.con(c, b);
                }
            }

            if (dsu2.find(c) == dsu2.find(b) && a == 2) {

                ans++;
            } else {
                if (a == 2) {
                    dsu2.con(c, b);
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (dsu1.find(i) != dsu1.find(1))
                return -1;
            if (dsu2.find(i) != dsu2.find(1))
                return -1;
        }

        return ans;
    }
};