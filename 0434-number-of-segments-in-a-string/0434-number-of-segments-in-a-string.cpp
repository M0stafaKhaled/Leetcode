class Solution {
public:
    int countSegments(string s) {

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            while (i < s.size() && s[i] == ' ')
                i++;
            bool check = 0;
            while (i < s.size() && s[i] != ' ') {
                i++;
                check = 1;
            }
            if (check)
                ans++;
        }
        return ans;
    }
};