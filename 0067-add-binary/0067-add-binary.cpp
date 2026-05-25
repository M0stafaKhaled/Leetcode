class Solution {
public:
    string addBinary(string a, string b) {

        string ans = "";

        int s1, s2;
        s1 = s2 = 0;
        int c = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (s1 < a.size() && s2 < b.size()) {
            int f = a[s1] - '0';
            int s = b[s2] - '0';
            if (f == 1 && s == 1) {
                if (c == 1)
                    ans += "1";
                else
                    ans += "0";
                c = 1;
            } else if (f == 1 || s == 1) {
                if (c == 1) {
                    ans += "0";

                } else {
                    ans += "1";
                }
            } else {
                if (c == 1) {
                    ans += "1";
                    c = 0;
                } else {
                    ans += "0";
                }
            }
            s1++;
            s2++;
        }

        while (s1 < a.size()) {
            int f = a[s1] - '0';
            if (f == 1) {
                if (c == 1) {
                    ans += "0";
                    // c = 0;
                } else {
                    ans += "1";
                }
            } else {
                if (c == 1) {
                    ans += "1";
                    c = 0;
                } else {
                    ans += "0";
                }
            }
            s1++;
        }

        while (s2 < b.size()) {
            int f = b[s2] - '0';
            if (f == 1) {
                if (c == 1) {
                    ans += "0";
                    // c = 0;
                } else {
                    ans += "1";
                }
            } else {
                if (c == 1) {
                    ans += "1";
                    c = 0;
                } else {
                    ans += "0";
                }
            }
            s2++;
        }

        if (c == 1)
            ans += "1";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};