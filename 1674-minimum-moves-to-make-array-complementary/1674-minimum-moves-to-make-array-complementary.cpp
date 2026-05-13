class Solution {
public:
    bool check(int a, int b, int sum, int limit) {

        if ((a + b) > sum) {

            int diff = (a + b) - sum;
            if (max(a, b) - diff <= 0)
                return false;
            return true;
        }

        int diff = sum - (a + b);
        if (min(a, b) + diff > limit)
            return false;
        return true;
    }
    int minMoves(vector<int>& nums, int limit) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> diff((2 * limit) + 2);
        for (int i = 0; i < nums.size() / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int same = a + b;
            diff[2] += 2;
            //   diff[2 * limit + 1] -= 2;

            diff[low] -= 1;
            diff[high + 1] += 1;

            diff[same] -= 1;
            diff[same + 1] += 1;
        }

        int cur = 0;

        for (int sum = 2; sum <= 2 * limit; sum++) {
            cur += diff[sum];
            ans = min(ans, cur);
        }

        return ans;
    }
};