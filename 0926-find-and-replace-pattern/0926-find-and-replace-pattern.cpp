class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        unordered_set<char> st;

        for (int i = 0; i < pattern.size(); i++) {
            st.insert(pattern[i]);
        }

        vector<string> ans;
        for (auto& word : words) {

            unordered_map<int, int> map2;
            int d = 0;
            for (int i = 0; i < word.size() && i < pattern.size(); i++) {
                int cur = word[i] - 'a';
                if (map2.find(cur) != map2.end()) {
                    cur = map2[cur];
                } else {
                    map2[cur] = pattern[i] - 'a';
                    cur = map2[cur];
                }
                if ((pattern[i] - 'a') == cur)
                    d++;
            }

            if (d == word.size() && map2.size() == st.size())
                ans.push_back(word);
        }

        return ans;
    }
};