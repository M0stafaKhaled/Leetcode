class Solution {
public:
    int solve(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            ans = min(ans, solve(nums[i]));
        }

        return ans;
    }
};