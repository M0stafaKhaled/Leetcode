class Solution {
public:
    bool isPowerOfFour(int n) {
        long long t = 1;
        while (t < n) {
            t *= 4;
        }
        return t == n;
    }
};