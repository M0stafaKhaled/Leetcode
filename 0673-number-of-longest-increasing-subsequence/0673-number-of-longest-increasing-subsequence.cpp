class Solution {
public:
    int db[2001];
    int length[20001];
    int count[20001];
    int solve(vector<int>& nums, int i) {
        if (i == nums.size())
            return 0;
        if (db[i] != -1)
            return db[i];
        int ans = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                ans = max(solve(nums, j) + 1, ans);
                if (length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = count[j];
                } else if (length[j] + 1 == length[i]) {
                    count[i] += count[j];
                }
            }
        }

        return db[i] = ans;
    }

    int print(vector<int>& nums, int i) {
        if (i == nums.size())
            return 0;
        int m = 0;
        for (int j = i; j < nums.size(); j++) {
            if (solve(nums, j) == db[i])
                m++;
            // else if(solve(nums,j) == db[i] ) m++;
        }

        return m;
    }
    int findNumberOfLIS(vector<int>& nums) {

        int ans = 0;
        int r = 0;
        memset(db, -1, sizeof db);

        for (int i = 0; i < nums.size(); i++) {

            length[i] = 1;
            count[i] = 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, solve(nums, i));
           // length[i] = 1;
        }
        cout << ans << endl;
        int d = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (length[i] == ans) {
                int mm = count[i];

                d += mm;
            }
        }

        return d;
    }
};