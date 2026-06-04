class Solution {
public:
    int solve(int num) {
        int ans = 0;
        int prev = num % 10;
        num /= 10;
        int cur = num % 10;
        num /= 10;
        while (num) {
            int next = num % 10;
            num /= 10;
            if (cur > prev && cur > next || cur < prev && cur < next) {
                ans++;
            }
            prev = cur;
            cur = next;
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {

        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += solve(i);
        }
        return ans;
    }
};