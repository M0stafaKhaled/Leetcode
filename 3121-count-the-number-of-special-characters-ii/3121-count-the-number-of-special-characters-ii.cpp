class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq1[26] = {0};
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            char cur = word[i];
            //    cout << cur - 'a' << " ";
            if (cur - 'a' >= 0 && cur - 'a' < 26) {
                if (freq1[cur - 'a'] == -1)
                    continue;
                if (freq1[cur - 'a'] == 2) {
                    freq1[cur - 'a'] = -1;
                } else
                    freq1[cur - 'a'] = 1;
            }

            else if (cur - 'A' >= 0 && cur - 'A' < 26) {
                if (freq1[cur - 'A'] == 2)
                    continue;
                if (freq1[cur - 'A'] == 1) {
                    freq1[cur - 'A'] = 2;
                } else {
                    freq1[cur - 'A'] = -1;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq1[i] == 2)
                ans++;
        }

        return ans;
    }
};