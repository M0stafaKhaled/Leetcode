class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, int idx, vector<int>& arr) {

        if (arr.size() == k) {
            ans.push_back(arr);
        }
        if (idx == n + 1)
            return;
        if (arr.size() > k)
            return;
    
        for (int i = idx; i <= n; i++) {
            arr.push_back(i);
            solve(n, k, i + 1, arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        vector<int> d;
        solve(n, k, 1, d);

        return ans;
    }
};