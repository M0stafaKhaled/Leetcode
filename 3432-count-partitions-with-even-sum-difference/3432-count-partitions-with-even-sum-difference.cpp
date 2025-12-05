class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suff(nums.size());
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            suff[i] = suff[i + 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            //int d = pre[i+1] - suff[i] ; 
            int diff = pre[i] - suff[i+1];
           // cout << pre[i] << "  " << suff[i] << endl;
            //cout << diff << endl;
            if (diff % 2 == 0)
                ans++;
        }

        return ans;
    }
};