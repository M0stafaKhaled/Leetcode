class Solution {
public:
    int minSteps(string s, string t) {

        unordered_map<char, int> m1, m2;
        int ans = 0;
        cout << s << endl;
        cout << t << endl;
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        // for (auto e : m2) {
        //     if (m1[e.first] > e.second) {
        //         ans += m1[e.first] - e.second;
        //     }
        // }

        for (auto e : m1) {
            if (m2[e.first] < e.second) {
                ans += abs(e.second - m2[e.first]);
            }
            cout << e.first << " " << e.second << " " << m2[e.first] << endl;
        }

        return ans;
    }
};