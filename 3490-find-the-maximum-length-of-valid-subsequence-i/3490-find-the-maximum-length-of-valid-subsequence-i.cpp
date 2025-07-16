class Solution {
public:
    int db[200000][3];
    int solve(vector<int>& nums, int i, int f) {
        if (nums.size() == i + 1)
            return 0;

        if (db[i][f] != -1)
            return db[i][f];
        int ans = 0;
        if (f == 1) {
            int cur = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if ((cur + nums[j]) % 2 == 1) {
                    ans = max(ans, solve(nums, j, f) + 1);
                    db[i][f] = ans;
                    return db[i][f];
                }
            }
        } else {
            int cur = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if ((cur + nums[j]) % 2 == 0) {
                    ans = max(ans, solve(nums, j, f) + 1);
                    db[i][f] = ans;
                    return db[i][f];
                }
            }
        }

        return db[i][f] = ans;
    }
    int maximumLength(vector<int>& nums) {

        memset(db, -1, sizeof db);
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans = max({solve(nums, i, 0) + 1, solve(nums, i, 1) + 1, ans});
        }
        return ans;
    }
};