class Solution {
public:
    int arr[26];
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        unordered_set<char> st;

        for (int i = 0; i < pattern.size(); i++) {
            arr[pattern[i] - 'a']++;
            st.insert(pattern[i]);
        }
        vector<int> freq;
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                freq.push_back(arr[i]);
            }
        }

        vector<string> ans;
        for (auto& word : words) {
            unordered_set<char> st2;
            unordered_map<int, int> map, map2;
            for (int i = 0; i < word.size(); i++) {
                st2.insert(word[i]);
                map[word[i] - 'a']++;
            }

            if (st2.size() != st.size())
                continue;

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
            cout << d << " " << word.size();
            if (d == word.size())
                ans.push_back(word);
        }

        return ans;
    }
};