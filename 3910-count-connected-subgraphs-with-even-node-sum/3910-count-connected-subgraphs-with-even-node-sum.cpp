class Solution {
public:
    vector<int> nums;
    vector<vector<int>> graph;
    vector<bool> vist;

    void solve(int node, int mask) {
        vist[node] = true;

        for (auto ch : graph[node]) {
            if ((mask & (1 << ch)) && !vist[ch]) {
                solve(ch, mask);
            }
        }
    }
    int evenSumSubgraphs(vector<int>& ds, vector<vector<int>>& edges) {
        nums = ds;

        int n = nums.size();
        graph = vector<vector<int>>(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = 0;
        int totalMasks = 1 << n;

        for (int mask = 1; mask < totalMasks; mask++) {
            vist = vector<bool>(n, false);

            int start = -1;

            // for (int i = 0; i < n; i++) {
            //     if (mask & (1 << i)) {
            //         cout << "1";
            //     } else
            //         cout << "0";
            // }
            // cout << endl;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    start = i;
                    break;
                }
            }

            solve(start, mask);

            int sum = 0;
            bool connected = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];

                    if (!vist[i]) {
                        connected = false;
                        break;
                    }
                }
            }

            if (connected && sum % 2 == 0) {
                ans++;
            }
        }

        return ans;
    }
};