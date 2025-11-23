class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        sort(nums.begin(), nums.end());

      
        vector<int> mod1;
        vector<int> mod2;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 == 1)
                mod1.push_back(nums[i]);
            else if (nums[i] % 3 == 2)
                mod2.push_back(nums[i]);
        }

        if (sum % 3 == 0)
            return sum;

        int removeCost = INT_MAX;

        if (sum % 3 == 1) {

            if (!mod1.empty()) {
                removeCost = min(removeCost, mod1[0]);
            }

            if (mod2.size() >= 2) {
                removeCost = min(removeCost, mod2[0] + mod2[1]);
            }
        }

        else if (sum % 3 == 2) {

            if (!mod2.empty()) {
                removeCost = min(removeCost, mod2[0]);
            }

            if (mod1.size() >= 2) {
                removeCost = min(removeCost, mod1[0] + mod1[1]);
            }
        }

        if (removeCost == INT_MAX)
            return 0;
        return sum - removeCost;
    }
};
