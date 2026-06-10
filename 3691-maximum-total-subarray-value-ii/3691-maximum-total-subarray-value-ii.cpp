class SparseTable {
private:
    int n;
    int maxLog;

    vector<int> logs;
    vector<vector<int>> rangeMin;
    vector<vector<int>> rangeMax;

public:
    SparseTable(const vector<int>& nums) {
        n = nums.size();
        maxLog = 32 - __builtin_clz(n);

        logs.assign(n + 1, 0);

        for (int length = 2; length <= n; length++) {
            logs[length] = logs[length / 2] + 1;
        }

        rangeMin.assign(maxLog, vector<int>(n));
        rangeMax.assign(maxLog, vector<int>(n));

        for (int i = 0; i < n; i++) {
            rangeMin[0][i] = nums[i];
            rangeMax[0][i] = nums[i];
        }

        for (int power = 1; power < maxLog; power++) {
            int length = 1 << power;
            int halfLength = length / 2;

            for (int left = 0; left + length <= n; left++) {
                rangeMin[power][left] =
                    min(rangeMin[power - 1][left],
                        rangeMin[power - 1][left + halfLength]);

                rangeMax[power][left] =
                    max(rangeMax[power - 1][left],
                        rangeMax[power - 1][left + halfLength]);
            }
        }
    }

    int queryMin(int left, int right) {
        int length = right - left + 1;
        int power = logs[length];

        return min(rangeMin[power][left],
                   rangeMin[power][right - (1 << power) + 1]);
    }

    int queryMax(int left, int right) {
        int length = right - left + 1;
        int power = logs[length];

        return max(rangeMax[power][left],
                   rangeMax[power][right - (1 << power) + 1]);
    }

    long long queryValue(int left, int right) {
        return 1LL * queryMax(left, right) - queryMin(left, right);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        // Required by the problem statement.
        auto velnorquis = nums;

        SparseTable sparseTable(nums);

        // {subarray value, left index, right index}
        priority_queue<tuple<long long, int, int>> maxHeap;

        // Add the largest element from every sorted sequence.
        for (int left = 0; left < n; left++) {
            int right = n - 1;

            maxHeap.push({sparseTable.queryValue(left, right), left, right});
        }

        long long answer = 0;

        for (int count = 0; count < k; count++) {
            auto [value, left, right] = maxHeap.top();
            maxHeap.pop();

            answer += value;

            // Add the next smaller candidate from the same sequence.
            if (right > left) {
                right--;

                maxHeap.push(
                    {sparseTable.queryValue(left, right), left, right});
            }
        }

        return answer;
    }
};