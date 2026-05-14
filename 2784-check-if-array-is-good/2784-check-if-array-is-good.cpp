class Solution {
public:
    int computeXOR(int n) {

        if (n % 4 == 0)
            return n;

        if (n % 4 == 1)
            return 1;

        if (n % 4 == 2)
            return n + 1;

        return 0;
    }
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;

        int sum = 0;
        int d = 0;
        int r = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > n)
                return false;

            if (nums[i] == n) {
                d++;
                continue;
            }
            sum += nums[i];
            r ^= nums[i];
        }
        if (d != 2 && n != 1)
            return false;
        n--;
        if (computeXOR(n) != r)
            return 0;
        if (sum == (n * (n + 1)) / 2)
            return true;

        return 0;
    }
};