class Solution {
public:
    struct BIT {
        vector<int> arr;
        int n;

        BIT(int size) {
            n = size;
            arr.resize(n + 1, 0);
        }

        void add(int idx, int val) {
            while (idx <= n) {
                arr[idx] += val;
                idx += idx & -idx;
            }
        }

        int get(int idx) {
            int res = 0;
            while (idx > 0) {
                res += arr[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    vector<int> processQueries(vector<int>& queries, int m) {
        int q = queries.size();
        int size = m + q + 2;

        BIT tree(size);
        vector<int> pos(m + 1);

        for (int i = 1; i <= m; i++) {
            pos[i] = q + i;
            tree.add(pos[i], 1);
        }

        int front = q;
        vector<int> ans;

        for (int cur : queries) {
            int idx = pos[cur];

            ans.push_back(tree.get(idx) - 1);

            tree.add(idx, -1);

            pos[cur] = front;
            tree.add(pos[cur], 1);

            front--;
        }

        return ans;
    }
};