class Solution {
public:
    void reverseString(vector<char>& s) {

        int end = s.size() - 1;
        for (int i = 0; i < s.size(); i++) {

            if (i >= end)
                return;

            swap(s[end], s[i]);
           // cout << s[i] << " ";
            end--;
        }
    }
};