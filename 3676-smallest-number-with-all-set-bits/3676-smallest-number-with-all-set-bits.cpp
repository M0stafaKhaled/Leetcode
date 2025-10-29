class Solution {
public:
    int smallestNumber(int n) {
        if (n == 1)
            return n;

        for (int i = 2; i < 31; i++) {
            int cur = 1 << i;
            if (cur - 1 >= n)
                return cur - 1;
            // cout << cur - 1 << endl;
        }

        return 1;
    }
};