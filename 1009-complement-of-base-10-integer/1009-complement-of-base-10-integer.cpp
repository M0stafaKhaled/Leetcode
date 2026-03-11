class Solution {
public:
    int bitwiseComplement(int n) {

        int end = 0;
        for (int i = 0; i < 31; i++) {
            int cur = (n >> i) & 1;
            if (cur)
                end = i;
        }
        for (int i = 0; i <= end; i++) {
            int cur = (n >> i) & 1;
            cur = 1;
            n ^= cur << i;
        }

        return n;
    }
};