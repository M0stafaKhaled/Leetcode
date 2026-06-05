class Solution {
public:
    struct Result {
        long long count;
        long long sum;
    };

    string s;

    Result memo[20][2][3][11][11];
    bool visited[20][2][3][11][11];

    bool isWave(int left, int middle, int right) {
        return (middle > left && middle > right) ||
               (middle < left && middle < right);
    }

    Result dfs(int pos, bool tight, int len, int prev2, int prev1) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (visited[pos][tight][len][prev2][prev1]) {
            return memo[pos][tight][len][prev2][prev1];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Result answer = {0, 0};

        for (int digit = 0; digit <= limit; digit++) {
            bool nextTight = tight && (digit == s[pos] - '0');

            Result child;

            if (len == 0 && digit == 0) {
                child = dfs(pos + 1, nextTight, 0, 10, 10);

                answer.count += child.count;
                answer.sum += child.sum;
            }

            else if (len == 0) {
                child = dfs(pos + 1, nextTight, 1, 10, digit);

                answer.count += child.count;
                answer.sum += child.sum;
            }

            else if (len == 1) {
                child = dfs(pos + 1, nextTight, 2, prev1, digit);

                answer.count += child.count;
                answer.sum += child.sum;
            }

            else {
                int addedWave = isWave(prev2, prev1, digit) ? 1 : 0;

                child = dfs(pos + 1, nextTight, 2, prev1, digit);

                answer.count += child.count;

                answer.sum += child.sum + child.count * addedWave;
            }
        }

        visited[pos][tight][len][prev2][prev1] = true;

        return memo[pos][tight][len][prev2][prev1] = answer;
    }

    long long solve(long long n) {
        if (n < 0) {
            return 0;
        }

        s = to_string(n);

        memset(visited, 0, sizeof(visited));

        return dfs(0, true, 0, 10, 10).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        long long melidroni = num1;

        return solve(num2) - solve(melidroni - 1);
    }
};