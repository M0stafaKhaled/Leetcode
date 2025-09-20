class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9 + 7;
        if (((target) / 2) + 1 > n) {
            return ((1L * n * (n + 1)) / 2) % mod;
        }

        int t = ((target) / 2);
        int x = abs(n - t) - 1;
        cout << t << endl;
        long long sum = (1L * t * (t + 1)) / 2;
        long long sum2 = ((x + 1) * ((1L * 2 * target) + x)) / 2;
        cout << sum << " " << sum2 << endl;
        return (sum + sum2) % mod;
        cout << ((target + 1) / 2) - 1 << endl;
        vector<int> arr;
        int last = target - 1;
        for (int i = 1; i < (target + 1) / 2; i++) {
            if (i + last > target) {
                cout << "test " << i << " " << last << endl;
            }
            cout << i << " " << last-- << endl;
        }

        return 1;
    }
};