class Solution {
public:
    int mask = 0;
    int solve(string& s) {
        int ret = 1;

        for (int i = 0; i < s.size(); i++) {
            int prev = i - 1;
            if (((mask >> i) & 1) ||
                (i && s[i] == s[i - 1] && !((mask >> (prev)) & 1)))
                continue;
            mask |= (1 << i);

            ret += solve(s);
            mask ^= (1 << i);
        }
        return ret;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        return solve(tiles) - 1;
    }
};