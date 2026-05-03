class Solution {
public:
    bool rotateString(string s, string goal) {
        unordered_map<char, string> map, map2;
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            int next = (i + 1) % n;
            map[s[i]].push_back(s[next]);
        }

        for (int i = 0; i < goal.size(); i++) {
            int next = (i + 1) % n;
            map2[goal[i]].push_back(goal[next]);
        }

        for (int i = 0; i < 26; i++) {
            sort(map[i + 'a'].begin(), map[i + 'a'].end());
            sort(map2[i + 'a'].begin(), map2[i + 'a'].end());
            if (map2[i + 'a'] != map[i + 'a']) {
                return false;
            }
        }

        return true;

        // abcde
        // eabcd
        // deabc
        // cdeab
    }
};