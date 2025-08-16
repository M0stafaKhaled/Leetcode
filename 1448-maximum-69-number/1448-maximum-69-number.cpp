class Solution {
public:
    int maximum69Number(int num) {
        int k = log10(num);
        k = pow(10, k);
        cout << k << endl;
        int ans = 0;
        bool check = false;
        while (num) {
            int d = num/k ;
            num = num % k;
            k /= 10;
             
            if (d == 6 && !check) {
                d = 9;
                check = true;
            }
            ans *= 10;
            ans += d;
        }
        return ans;
    }
};