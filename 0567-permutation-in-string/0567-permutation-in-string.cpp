class Solution {
public:
    int map1[26];
    int map2[26];
    bool checkInclusion(string s1, string s2) {
        int sz1 = 0;
        string s3 = s1;
        sort(s3.begin(), s3.end());
        cout << s3 << endl;
        for (int i = 0; i < s1.size(); i++) {
            if (map1[s1[i] - 'a'] == 0) {
                sz1++;
            }
            map1[s1[i] - 'a']++;
        }

        int start = 0;
        int sz2 = 0;
        for (int i = 0; i < s2.size(); i++) {
            int cur = s2[i] - 'a';
            if (map2[cur] == 0) {
                sz2++;
            }
            map2[cur]++;

            while (i >= start && (i - start) + 1 == s1.size()) {
                // string g = s2.substr(start, (i - start) + 1);
                // sort(g.begin(), g.end());
                // cout << g << endl;
                bool valid = true;
                for (int j = 0; j < 26; j++) {
                    if (map2[j] != map1[j]) {
                        valid = 0;

                        break;
                    }
                }

                if (valid)
                    return true;

                map2[s2[start] - 'a']--;
                if (map2[s2[start] - 'a'] == 0) {
                    sz2--;
                }
                start++;
            }
        }

        return 0;
    }
};