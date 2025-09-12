class Solution {
public:
    bool doesAliceWin(string s) {

        int count = 0;
        int last = 0;
        int pre = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U') {
                pre = last;
                last = i;
                count++;
            }
        }

        if (count == 0)
            return 0;
        if (count % 2 == 1)
            return 1;

        return 1;
    }
};