class Solution {
public:
    struct bst {
        unordered_map<int, int> arr;
        int sz;
        bst(int n) { sz = n; }

        long long get(int idx) {
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
        }
    };
    bool isIdealPermutation(vector<int>& nums) {

        int n = nums.size();

        bst tree(1e8);
        long long l = 0;
        long long g = 0;

        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) {
                l++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int cur = nums[i];

            g += tree.get(cur);
            // cout << g << endl;
            tree.add(cur + 1, 1);
        }
        // cout << l << " " << g << endl;
        return l == g;
    }
};