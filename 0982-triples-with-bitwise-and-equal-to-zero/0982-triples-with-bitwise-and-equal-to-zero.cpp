class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int SIZE = 1 << 16;

        vector<int> freq(SIZE, 0);

        for (int a : nums) {
            for (int b : nums) {
                freq[a & b]++;
            }
        }

        int ans = 0;

        for (int x : nums) {
            for (int mask = 0; mask < SIZE; mask++) {
                if ((mask & x) == 0) {
                    ans += freq[mask];
                }
            }
        }

        return ans;
    }
};