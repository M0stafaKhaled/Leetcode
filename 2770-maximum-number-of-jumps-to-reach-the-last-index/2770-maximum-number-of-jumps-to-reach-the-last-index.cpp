class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        vector<int> arr(nums.size(), -1);
        arr[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                if (arr[i] != -1 && abs(nums[i] - nums[j]) <= target) {
                    arr[j] = max(arr[i] + 1, arr[j]);
                }
            }
        }

        return arr[nums.size() - 1];
    }
};