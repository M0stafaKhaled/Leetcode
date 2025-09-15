class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for (int i = 0; i < brokenLetters.size(); i++) {
            st.insert(brokenLetters[i]);
        }

        int ans = 0;

        for (int i = 0; i < text.size(); i++) {
            bool check = false;
            while (i < text.size() && text[i] != ' ') {
                if (st.find(text[i]) != st.end())
                    check = true;
                i++; 
            }
            ans += !check;
        }

        return ans;
    }
};