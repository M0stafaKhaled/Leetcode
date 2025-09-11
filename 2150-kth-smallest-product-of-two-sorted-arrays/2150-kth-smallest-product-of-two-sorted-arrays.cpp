class Solution {
public:
    long long floordiv(long long x, long long y) {
        if (y < 0) {
            x = -x;
            y = -y;
        }
        if (x >= 0)
            return x / y;
        return -((-x + y - 1) / y);
    }

    long long solve(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long count = 0;
        int m = nums2.size();

        for (int a : nums1) {
            if (a > 0) {
                long long target = floordiv(mid, a);
                int st = 0, end = m - 1, idx = -1;
                while (st <= end) {
                    int id = st + (end - st) / 2;
                    if (nums2[id] <= target) {
                        idx = id;
                        st = id + 1;
                    } else {
                        end = id - 1;
                    }
                }
                if (idx != -1)
                    count += idx + 1;
            } else if (a < 0) {
                int st = 0, end = m - 1, idx = m;
                while (st <= end) {
                    int id = st + (end - st) / 2;
                    if ((long long)a * nums2[id] <= mid) {
                        idx = id;
                        end = id - 1;
                    } else {
                        st = id + 1;
                    }
                }
                count += m - idx;
            } else {
                if (mid >= 0)
                    count += m;
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long st = -1e11, end = 1e11;
        long long ans = 0;
        while (st <= end) {
            long long mid = st + (end - st) / 2;
            if (solve(nums1, nums2, mid) >= k) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};
