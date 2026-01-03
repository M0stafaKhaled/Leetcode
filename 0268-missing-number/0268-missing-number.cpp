class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // code to get sum from 0 to n
        // code to get sum form this array nums

        int sum1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum1 += nums[i];
        }
        int sum2 = 0;
        for (int i = 0; i <= n; i++) {
            sum2 += i;
        }

        return sum2 - sum1 ; 
    }
};