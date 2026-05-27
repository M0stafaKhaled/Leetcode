class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq1[26] = {};
        int freq2[26] = {};
        int skip[26] = {};
        int take[26] = {};
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            char cur = word[i];
            if (cur - 'a' >= 0 && cur - 'a' < 26) {
                freq1[cur - 'a']++;
                if (freq2[cur - 'a'] == -1) {
                    skip[cur - 'a'] = 1;
                }

            }

            else if (cur - 'A' >= 0 && cur - 'A' < 26) {
                if (freq1[cur - 'A'] > 0 && freq2[cur - 'A'] != -1) {
                    take[cur - 'A'] = 1;
                }

                freq2[cur - 'A'] = -1;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (take[i] == 1 && skip[i] == 0)
                ans++;
        }

        return ans;
    }
};