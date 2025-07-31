class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int x = 10;
        int prev = 9;
        int cur = prev;
        for (int i = 0; i < n-1; i++) {

            cur*=(prev-i) ; 
            x += cur;
        }
        return x;
    }
};