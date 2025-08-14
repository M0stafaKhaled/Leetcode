class Solution {
public:
    string largestGoodInteger(string num) {
        int n = 0;
        string ans = "";
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                if (num[i] - '0' >= n) {
                    n = num[i] - '0';
                    ans = "";
                    ans += num[i];
                    ans += num[i + 1];
                    ans += num[i + 2];
                }
            }
        }

        return ans;
    }
};