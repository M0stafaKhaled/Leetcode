class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int sum = 1;
        int start = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum *= nums[i];

            while (start <= i && sum >= k) {
                sum /= nums[start++];
            }
          
            int cur = (i - start) + 1;
            ans += cur;
        }

        return ans;
    }
};