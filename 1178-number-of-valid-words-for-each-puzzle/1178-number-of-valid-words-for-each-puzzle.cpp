class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words,
                                    vector<string>& puzzles) {
        int p = puzzles.size();
        vector<int> ans(p);
        unordered_map<int, int> map;
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (char w : words[i]) {
                mask |= (1 << (w - 'a'));
            }

            map[mask]++;
        }

        for (int i = 0; i < p; i++) {
            int init = 0;
            int firstBit = 1 << (puzzles[i][0] - 'a');
            for (char w : puzzles[i]) {
                init |= (1 << (w - 'a'));
            }
            int cur = 0;
            for (auto e : map) {
                if ((e.first & init) == e.first && (e.first & firstBit) != 0) {
                    cur += e.second;
                }
            }

            ans[i] = cur;
        }
        return ans;
    }
};