class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int c = 0;
        // 01
        // 10
        for (int i = 0; i <= 31; i++) {
            int abit = (a >> i) & 1;
            int bbit = (b >> i) & 1;

            if (abit && bbit && c == 1) {
                ans |= (1 << i);
                c = 1;
            } else if (abit && bbit) {
                c = 1;
            }

            else if (abit && c == 1) {
                c = 1;
            } else if (bbit && c == 1) {
                c = 1;
            } else if (c == 1) {
                ans |= (1 << i);
                c = 0;
            } else if (abit || bbit) {
                ans |= (1 << i);
                c = 0;
            }
        }

        return ans;
    }
};