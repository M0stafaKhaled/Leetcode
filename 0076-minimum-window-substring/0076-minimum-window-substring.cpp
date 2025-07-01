class Solution {
public:
    bool isTheSame(int freq[], int freq2[]) {
        for (int j = 0; j < 128; j++) {
            if (freq2[j] < freq[j]) {
               return false;
            }
        }

        return true ; 
    }
    string minWindow(string s, string t) {

        int freq[128];
        int freq2[128];

        for (int i = 0; i < t.size(); i++) {
            freq[t[i] - 'A']++;
        }
        int size = t.size() - 1;
        int start = 0;
        int left = -1;
        int right = s.size() + 110;
        for (int i = 0; i < s.size(); i++) {
            freq2[s[i] - 'A']++;

            if (i >= size) {
                while (i>=start &&isTheSame(freq , freq2)) {
                    if (right - left > i - start) {
                        left = start;
                        right = i;
                    }
                    freq2[s[start] - 'A']--;
                    start++;
                }
            }
        }

        if (left == -1)
            return "";
        string ans = "";
        for (int i = left; i <= right; i++) {
            ans += s[i];
        }
        return ans;
    }
};