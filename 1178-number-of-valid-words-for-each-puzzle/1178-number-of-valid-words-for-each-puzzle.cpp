class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words,
                                    vector<string>& puzzles) {
        int p = puzzles.size();
        vector<int> ans(p);
        vector<int> masks(words.size());
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (char w : words[i]) {
                mask |= (1 << (w - 'a'));
            }

            masks[i] = mask;
        }

        for (int i = 0; i < p; i++) {
            int init = 0;
            int firstBit = 1 << (puzzles[i][0] - 'a');
            for (char w : puzzles[i]) {
                init |= (1 << (w - 'a'));
            }
            int cur = 0;
            for (int e : masks) {
                if ((e & init) == e && (e & firstBit) != 0) {
                    cur++;
                }
            }

            ans[i] = cur;
        }
        return ans;
    }
};