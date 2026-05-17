class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < nums.size(); j++) {
                int len = (j - i) + 1;
                freq[nums[j]]++;
                if (freq[target] > len / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};