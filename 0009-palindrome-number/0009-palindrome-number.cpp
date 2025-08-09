class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        if (x == 0)
            return 1;
        int len = log10(x);
        long long start = pow(10, len);
        long long end = 10;
        int x1 = x;
        int x2 = x;
        while (start >= end) {
            cout << start << " " << end << endl;
            int a = x1 / start;
            int b = x2 % end;

            cout << a << " " << b << endl;
            x1 = (x % start);
            x2 = x2 / 10;
            start /= 10;
            end = 10;

            if (a != b)
                return 0;
        }

        return 1;
    }
};