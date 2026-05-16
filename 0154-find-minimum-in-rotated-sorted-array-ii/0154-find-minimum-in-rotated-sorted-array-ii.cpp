class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int start = 0;
        int n = nums.size() - 1;
        int end = n / 2;
        while (end >= start) {
            int mid = (start + end) / 2;
            ans = min({nums[start], nums[end], nums[mid], ans});
            if (nums[mid] >= nums[start] && nums[mid] >= nums[end]) {
                start = mid + 1;
            } else if (nums[mid] <= nums[start] && nums[mid] <= nums[end]) {
                end = mid - 1;
            } else {
                if (nums[mid] >= nums[start]) {
                    end = mid - 1;

                } else {
                    start = mid + 1;
                }
            }
        }

        start = n / 2;
        end = n;

        while (end >= start) {
            int mid = (start + end) / 2;
            ans = min({nums[start], nums[end], nums[mid], ans});
            if (nums[mid] >= nums[start] && nums[mid] >= nums[end]) {
                start = mid + 1;
            } else if (nums[mid] <= nums[start] && nums[mid] <= nums[end]) {
                end = mid - 1;
            } else {
                if (nums[mid] >= nums[start]) {
                    end = mid - 1;

                } else {
                    start = mid + 1;
                }
            }
        }

        start = 0;
        end = n / 2;

        while (end >= start) {
            int mid = (start + end) / 2;
            ans = min({nums[start], nums[end], nums[mid], ans});
            if (nums[mid] >= nums[start] && nums[mid] >= nums[end]) {
                end = mid - 1;
            } else if (nums[mid] <= nums[start] && nums[mid] <= nums[end]) {
                start = mid + 1;
            } else {
                if (nums[mid] >= nums[start]) {
                    start = mid + 1;

                } else {
                    end = mid - 1;
                }
            }
        }

        start = n / 2;
        end = n;
        while (end >= start) {
            int mid = (start + end) / 2;
            ans = min({nums[start], nums[end], nums[mid], ans});
            if (nums[mid] >= nums[start] && nums[mid] >= nums[end]) {
                end = mid - 1;
            } else if (nums[mid] <= nums[start] && nums[mid] <= nums[end]) {
                start = mid + 1;
            } else {
                if (nums[mid] >= nums[start]) {
                    start = mid + 1;

                } else {
                    end = mid - 1;
                }
            }
        }

        return ans;
    }
};