class Solution {
public:
    int numTrees(int n) {
        vector<int> db(n+2);
        db[0] = 1;
        db[1] = 1;
        db[2] = 2;

        for (int i = 3; i <=n; i++) {
            for (int j = 1; j <=i; j++) {
                if (i >= j)
                    db[i] += db[j - 1] * db[i - j];
            }
        }

        return db[n];
    }
};