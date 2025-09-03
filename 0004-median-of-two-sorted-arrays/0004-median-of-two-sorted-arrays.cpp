class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int num) {
        int start = 0;
        int end = nums1.size() - 1;
        int n1 = 0;
        while (end >= start) {
            int mid = (end + start) / 2;
            if (nums1[mid] <= num) {
                start = mid + 1;
                n1 = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        start = 0;
        end = nums2.size() - 1;
        int n2 = 0;

        while (end >= start) {
            int mid = (end + start) / 2;
            if (nums2[mid] <= num) {
                start = mid + 1;
                n2 = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return n1 + n2;
    }

    int solve2(vector<int>& nums1, vector<int>& nums2, int se) {
        int ans = 0;
        int start = -1e6;
        int end = 1e6;
        while (end >= start) {
            int mid = (end + start) / 2;
        
            int d = solve(nums1, nums2, mid);
            if (d >= se) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int n = nums1.size() + nums2.size();
        int se = (n + 1) / 2;
        int se2 = se + (n % 2 == 0);

        return (solve2(nums1, nums2, se) + solve2(nums1, nums2, se2)) * .5;
    }
};