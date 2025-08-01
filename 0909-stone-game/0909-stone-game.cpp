class Solution {
public:
    int db[500][2] ; 
    int solve(vector<int>& piles, int i, int j, bool player) {
        if (i > j)
            return 0;
       if(db[i][player] != -1) return db[i][player] ; 
        int v1 = player ? piles[i] : -piles[i];
        int v2 = player ? piles[j] : -piles[j];
        int ans;
        if (player) {
            ans = max(solve(piles, i + 1, j, !player) + v1,
                      solve(piles, i, j - 1, !player) + v2);
        } else {
            ans = min(solve(piles, i + 1, j, !player) + v1,
                      solve(piles, i, j - 1, !player) + v2);
        }

        return db[i][player] = ans;
    }
    bool stoneGame(vector<int>& piles) {
        memset(db , -1 , sizeof db) ; 
        return 1;
    }
};