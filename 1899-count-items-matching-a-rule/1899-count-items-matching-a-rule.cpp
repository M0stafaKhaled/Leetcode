class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey,
                     string ruleValue) {

        unordered_map<int, string> m;
        m[0] = "type";
        m[1] = "color";
        m[2] = "name";
        int ans = 0;
        for (int i = 0; i < items.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (m[j] == ruleKey && items[i][j] == ruleValue)
                    ans++;
            }
        }

        return ans;
    }
};