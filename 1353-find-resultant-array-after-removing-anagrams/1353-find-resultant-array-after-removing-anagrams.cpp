class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_set<string> st;
        unordered_map<int, bool> map;
        unordered_map<int, string> map2;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (map2.find(i) != map2.end()) {
                ans.push_back(map2[i]);
            } else {
                ans.push_back(words[i]);
                sort(words[i].begin(), words[i].end());
            }

            while (i + 1 < words.size()) {
                map2[i + 1] = words[i + 1];
    
                sort(words[i + 1].begin(), words[i + 1].end());
                if (words[i] == words[i + 1])
                    i++;
                else {
                    break;
                }
            }
        }

        return ans;
    }
};