class Solution {
public:
    bool isSameAfterReversals(int num) {
        int re = 0;
        int og = num;
        while (og) {
            re += og % 10;
            og /= 10;
            if (og)
                re *= 10;
        }
        cout << re << " " << log10(re) << " " << log10(num);
        return ceil(log10(re)) == ceil(log10(num));
    }
};