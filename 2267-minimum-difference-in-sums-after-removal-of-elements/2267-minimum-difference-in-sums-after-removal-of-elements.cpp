class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        vector<long long> left_sum(2 * n);
        vector<long long> right_sum(2 * n + 1);
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> pq2;
        long long sum = 0;
        for (int i = 0; i < 2 * n; ++i) {
            pq.push(nums[i]);
            sum += nums[i];

            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == n) {
                left_sum[i] = sum;
            }
        }

        int start = 3 * n - 1;
        sum = 0;
        for (int i = start; i >= n; --i) {
            pq2.push(nums[i]);
            sum += nums[i];

            if (pq2.size() > n) {
                sum -= pq2.top();
                pq2.pop();
            }

            if (pq2.size() == n) {
                right_sum[i] = sum;
            }
        }

        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, left_sum[i] - right_sum[i + 1]);
        }
        return res;
    }
};