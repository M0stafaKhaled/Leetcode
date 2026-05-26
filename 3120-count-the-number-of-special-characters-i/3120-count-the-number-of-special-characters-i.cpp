class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq1[26] = {};
        int freq2[26] = {};

        for (int i = 0; i < word.size(); i++) {
            char cur = word[i];
            if (cur - 'a' >= 0 && cur - 'a' < 26)
                freq1[cur - 'a']++;
            if (cur - 'A' >= 0 && cur - 'A' < 26)
                freq2[cur - 'A']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (min(freq1[i], freq2[i]) >= 1)
                ans++;
        }

        return ans;
    }
};