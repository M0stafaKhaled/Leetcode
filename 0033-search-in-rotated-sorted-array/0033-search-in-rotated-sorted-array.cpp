class Solution {
public:
    int bin(vector<int>& nums, int target, int start, int end) {

        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int solve(vector<int>& nums, int target, int start, int end) {
        int mid = (start + end) / 2;
        if (mid == start) {
            if (nums[start] == target)
                return start;
            if (nums[end] == target)
                return end;
        }
        if (start == end) {
            if (nums[start] == target)
                return start;
            return -1;
        }
        // check which on is sorted
        if (nums[mid] > nums[start]) {
            int ans = bin(nums, target, start, mid);
            if (ans != -1)
                return ans;

            return solve(nums, target, mid, end);

        } else {
            int ans = bin(nums, target, mid, end);
            if (ans != -1)
                return ans;

            return solve(nums, target, start, mid);
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {

        return solve(nums, target, 0, nums.size() - 1);
    }
};