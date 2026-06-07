class Solution {
public:
    int countSubstrings(string s) {
        // aaaa
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int point = i;
            int start = point - 1;
            int end = point + 1;
            ans++;
            while (start >= 0 && end < s.size()) {
                if (s[start] == s[end]) {
                    ans++;
                } else
                    break;
                start--;
                end++;
            }
            start = point;
            end = point + 1;
            while (start >= 0 && end < s.size() && s[start] == s[end] ) {

                ans++;
                start--;
                end++;
            }
        }

        return ans;
    }
};