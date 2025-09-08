class Solution {
public:
    int minSteps(string s, string t) {

        unordered_map<char, int> m1, m2;
        int ans = 0;
       
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
      

        for (auto e : m1) {
            if (m2[e.first] < e.second) {
                ans += abs(e.second - m2[e.first]);
            }
        }

        return ans;
    }
};