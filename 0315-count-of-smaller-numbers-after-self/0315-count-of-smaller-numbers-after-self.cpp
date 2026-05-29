class Solution {
public:
    struct bst {
        unordered_map<int, int> arr;
        int sz;
        bst(int n) { sz = n; }

        int get(int idx) {
            int res = 0;
            while (idx) {
                res += arr[idx];
                idx -= (idx & -idx);
            }
            return res;
        }

        void add(int idx, int val) {
            while (idx < sz) {
                arr[idx] += val;
                idx += (idx & -idx);
            }
            // cout << endl;
        }
    };
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        bst tree(1e8);
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            int cur = nums[i] + 1e4 + 1;
            tree.add(cur, 1);
            ans.push_back(tree.get(cur - 1));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};