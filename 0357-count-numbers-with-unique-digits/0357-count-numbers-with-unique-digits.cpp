class Solution {
public:
    int solve(int i, int vist, int n) {
        if (n == 0)
            return 1;
        int ans = 0;
        for (int j = 0; j <= 9; j++) {
            if (i == 0 && j == 0)
                continue;
            if (vist&(1<<j))
                continue;
           
            vist |= (1<<j) ; 
            ans += solve(i + 1, vist, n - 1);
            vist ^= (1<<j);
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        // 090

        int ans = 0;
        for (int i = 0; i <=n; i++) {
          
            ans += solve(0, 0, i);
        }
        return ans;
    }
};