class Solution {
public:
    vector<bool> pr;

    void solve(int mx) {
        pr = vector<bool>(mx + 3, true);

        if (mx >= 0) pr[0] = false;
        if (mx >= 1) pr[1] = false;

        for (int i = 2; 1LL * i * i <= mx; i++) {
            if (pr[i]) {
                for (long long j = 1LL * i * i; j <= mx; j += i) {
                    pr[j] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        solve(mx);

        queue<int> q;
        vector<int> cost(n, 1e9);

        q.push(0);
        cost[0] = 0;

        // value -> all indices having this value
        vector<vector<int>> pos(mx + 1);

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<bool> usedPrime(mx + 1, false);

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            int x = nums[z];

            if (z == n - 1) {
                return cost[z];
            }

            if (z + 1 < n && cost[z + 1] > cost[z] + 1) {
                cost[z + 1] = cost[z] + 1;
                q.push(z + 1);
            }

            if (z > 0 && cost[z - 1] > cost[z] + 1) {
                cost[z - 1] = cost[z] + 1;
                q.push(z - 1);
            }

            if (pr[x] && !usedPrime[x]) {
                usedPrime[x] = true;

                for (int val = x; val <= mx; val += x) {
                    for (int k : pos[val]) {
                        if (cost[k] > cost[z] + 1) {
                            cost[k] = cost[z] + 1;
                            q.push(k);
                        }
                    }
                    pos[val].clear();
                }
            }
        }

        return cost[n - 1];
    }
};