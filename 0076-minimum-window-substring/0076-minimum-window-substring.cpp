class Solution {
public:
    int map1[129];
    int map2[129];
    string minWindow(string s2, string s1) {

        int sz1 = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (map1[s1[i] - 'A'] == 0) {
                sz1++;
            }
            map1[s1[i] - 'A']++;
        }

        int start = 0;
        int sz2 = 0;
        int len = INT_MAX;
        string ans = s2;
        int a1 = -1;
        int a2 = -1;
        for (int i = 0; i < s2.size(); i++) {
            int cur = s2[i] - 'A';
            if (map2[cur] == 0) {
                sz2++;
            }
            map2[cur]++;

            while (i >= start && sz2 >= sz1) {
                // string g = s2.substr(start, (i - start) + 1);
                // sort(g.begin(), g.end());
                // cout << g << endl;
                bool valid = true;
                for (int j = 0; j < 128; j++) {
                    if (map2[j] < map1[j]) {
                        valid = 0;

                        break;
                    }
                }
                while (valid && i >= start && sz2 >= sz1) {
                    int cur_ans = (i - start) + 1;
                    if (a1 == -1 || cur_ans <= (a2 - a1) + 1) {
                        len = cur_ans;

                        a1 = start;
                        a2 = i;
                    }
                    map2[s2[start] - 'A']--;
                    if (map2[s2[start] - 'A'] == 0) {
                        sz2--;
                    }
                    start++;
                    for (int j = 0; j < 128; j++) {
                        if (map2[j] < map1[j]) {

                            valid = 0;

                            break;
                        }
                    }
                }

                if (!valid)
                    break;
            }
        }
        if (len == INT_MAX || a1 == -1)
            return "";

        return s2.substr(a1, (a2 - a1) + 1);
    }
};