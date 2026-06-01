class Solution {
public:
    int addDigits(int num) {
        int re = num;

        while (num / 10 > 0) {
            int x = num;
            re = 0;
            while (x) {
                re += x % 10;
                x /= 10;
            }
            num = re;
        }

        return re;
    }
};