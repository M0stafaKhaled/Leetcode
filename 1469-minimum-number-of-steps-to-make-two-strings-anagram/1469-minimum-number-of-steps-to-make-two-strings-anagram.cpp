class Solution {
public:
    int m1[26], m2[26];
    int minSteps(string s, string t) {

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            m1[s[i] - 'a']++;
            m2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (m2[i] < m1[i]) {
                ans += m1[i] - m2[i];
            }
        }

        return ans;
    }
};