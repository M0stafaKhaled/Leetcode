class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> nums2 = nums;

        sort(nums2.begin(), nums2.end());

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {

            int start = 0;
            int end = nums.size() - 1;
            int cur = 0;
            while (end >= start) {
                int mid = (end + start) / 2;

                if (nums2[mid] >= nums[i]) {
                    cur = i;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            ans[i] = start;
        }

        return ans;
    }
};