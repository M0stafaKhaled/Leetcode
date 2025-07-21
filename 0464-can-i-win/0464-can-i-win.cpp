class Solution {
public:
    vector<int> arr;

    int db[(1 << 21) - 1];
    bool solve(int x, int y, int total, bool player, int mask) {

        if (db[mask] != -1)
            return db[mask];
        for (int i = 0; i < arr.size(); i++) {

            if (!((mask >> i) & 1)) {
                if (total + arr[i] >= y)
                    return db[mask] = 1;

                int d = 1 << i | mask;
                if (!solve(x, y, total + arr[i], !player, d)) {
                    return db[mask] = 1;
                }
            }
        }

        return db[mask] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal)
            return false;
        arr = vector<int>(maxChoosableInteger);
        for (int i = 0; i < maxChoosableInteger; i++) {
            arr[i] = i + 1;
        }
        memset(db, -1, sizeof db);
        return solve(maxChoosableInteger, desiredTotal, 0, 1, 0);
    }
};