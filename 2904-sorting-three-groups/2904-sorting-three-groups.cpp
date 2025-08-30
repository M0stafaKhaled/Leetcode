class Solution {
public:
    int db[1001];
    int solve(int i, vector<int>& nums) {
        if (i == nums.size())
            return 0;
        int cur = 0;
        if (db[i] != -1)
            return db[i];
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j])
                continue;

            cur = max(solve(j, nums) + 1, cur);
        }

        return db[i] = cur;
    }
    int minimumOperations(vector<int>& nums) {

        memset(db, -1, sizeof db);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, solve(i, nums) + 1);
        }

        return nums.size() - ans;
    }
};