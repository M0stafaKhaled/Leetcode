class Solution {
public:
    int db[1001][1001];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == nums1.size())
            return 0;
        if (j == nums2.size())
            return 0;

        if(db[i][j] != -1) return db[i][j] ; 
        int ans = 0;
        if (nums1[i] == nums2[j]) {
            ans = solve(nums1, nums2, i + 1, j + 1) + 1;
        } else {
            return db[i][j] = 0;
        }

        return db[i][j] = ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(db, -1, sizeof db);

        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                ans = max(ans, solve(nums1, nums2, i, j));
            }
        }
        return ans;
    }
};