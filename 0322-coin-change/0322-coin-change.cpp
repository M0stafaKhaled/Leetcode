class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;
        int n = coins.size();
        const int f = 1e4;
        int db[f + 2];
        for (int i = 1; i <= amount; i++) {
            db[i] = INT_MAX - 1;
        }

        db[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                int c = coins[j];
                if (i - c >= 0) {
                    db[i] = min(db[i - c] + 1, db[i]);
                }
            }
        }
        if (db[amount] == INT_MAX - 1)
            return -1;
        return db[amount];
    }
};