class Solution {
public:
    class fnw {
    public:
        vector<long long> arr;
        int n = 0;
        fnw(int size) {
            n = size;
            arr.resize(n + 1);
        }

        void add(int idx, int val) {

            while (idx <= n) {
                arr[idx] += val;
                idx += (-idx) & idx;
            }
        }
        long long get(int idx) {
            long long ans = 0;
            while (idx > 0) {
                ans += arr[idx];
                idx -= idx & -idx;
            }
            return ans;
        }
    };
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        long long ans = 0;
        int n = nums.size();
        int size = 2 * n + 5;
        int offset = n + 2;

        fnw bit(size);

        int prefix = 0;

        bit.add(prefix + offset, 1);

        for (int x : nums) {
            int val = (x == target ? 1 : -1);
            prefix += val;
            ans += bit.get(prefix + offset - 1);
            bit.add(prefix + offset, 1);
        }
        return ans;
    }
};