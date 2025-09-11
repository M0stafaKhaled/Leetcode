class Solution {
public:
    string sortVowels(string s) {

        vector<char> t;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U')
                t.push_back(s[i]);
        }

        sort(t.begin(), t.end());
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U') {
                s[i] = t[start++];
            }
        }

        return s;
    }
};