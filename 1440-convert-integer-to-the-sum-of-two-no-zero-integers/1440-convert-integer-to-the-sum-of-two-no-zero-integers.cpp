class Solution {
public:
    bool cont(int num) {
        while (num) {
            if (num > 0 && num % 10 == 0)
                return 1;
            num /= 10;
        }
        return 0;
    }
    vector<int> getNoZeroIntegers(int n) {

        int a = 1;
        int b = n - 1;
        while (cont(a) || cont(b)) {

            a++;
            b--;
        }

        return {a, b};
    }
};