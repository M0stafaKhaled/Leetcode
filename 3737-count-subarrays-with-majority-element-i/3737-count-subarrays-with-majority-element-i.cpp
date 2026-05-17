class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = i; j < nums.size(); j++) {
                int len = (j - i) + 1;
                if (nums[j] == target)
                    count++;
                if (count > len / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};