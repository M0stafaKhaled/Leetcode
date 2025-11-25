class Solution {
public:
    int smallestRepunitDivByK(int k) {

        if (k % 2 == 0)
            return -1;
        if (k == 1)
            return 1;

        unsigned long long max = 1e18;
        unsigned long long cur = 1;
        int n = 1;

        while (max >= cur && n <=1e5) {
            if ((cur) % k == 0)
                return n;

            n++;
            cur = ((cur * 10) + 1) % k;
        }
        cout << cur << endl;
        return -1;
    }
};