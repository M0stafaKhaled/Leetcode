class Solution {
public:
    int solve(vector<int>& nums, int maxDist) {
        int count = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > maxDist) {
                left++;
            }
            count += right - left;
        }

        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums[nums.size() - 1] - nums[0];

        int ans = end;

        while (end >= start) {

            int mid = (start + end) / 2;

            int d = solve(nums, mid);

            if (d >= k) {
                ans = mid;

                end = mid - 1;

            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};