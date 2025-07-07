class Solution {
public:
    int solve(int n, bool check) {
        if (n == 1)
            return 1;

        if (n % 2 == 1 || check) {
            return 2 * solve(n / 2, !check);
        } else {
            return 2 * (solve(n / 2, !check)) - 1;
        }
    }
    int lastRemaining(int n) {
        if (n == 1)
            return 1;

        return solve(n, true);
    }
};