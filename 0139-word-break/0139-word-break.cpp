class Solution {
public:
    unordered_map<string, bool> map;
    bool solve(string& s, string& cur, vector<string>& wordDict) {

        if (cur.size() == s.size())
            return cur == s;
        if (cur.size() > s.size())
            return false;
        if (cur.size()) {
            if (cur[0] != s[0]) {
                map[cur] = false;
                return false;
            }
        }
        if (map.find(cur) != map.end())
            return map[cur];
        for (int k = 0; k < wordDict.size(); k++) {
            string d = cur + wordDict[k];
            if (s.substr(0, d.size()) != d) {
                map[d] = false;
                continue;
            }
            bool ans = solve(s, d, wordDict);
            if (ans) {
                map[cur] = true;
                return 1;
            }
        }
        map[cur] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string d = "";
        return solve(s, d, wordDict);
    }
};