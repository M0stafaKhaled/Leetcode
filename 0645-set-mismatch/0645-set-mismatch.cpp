class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int sum = 0;
        int n = nums.size();
        int sh = (n * (n + 1)) / 2;
        int x = 0;
        int num = 0;
        int all = 0;
        for (int i = 1; i <= n; i++) {
            all ^= i ^ nums[i - 1];
        }
        int diff = all & -all;
        int a = 0;
        int b = 0;

        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & diff)) {
                a ^= nums[i];
            } else
                b ^= nums[i];
        }

        for (int i = 1; i <=nums.size(); i++) {
            if ((i & diff)) {
                a ^= i;
            } else
                b ^= i;
        }
        bool swaps = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == b) {
                swaps = true;
                break;
            }
        }
        if (swaps)
            swap(a, b);
        return {a, b};
    }
};