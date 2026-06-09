class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // ...min , max ....
        // min............max
        // max............min
        // min,max...............
        //............,min,max
        //...min.....max

        int max_val = 0;
        int max_index = 0;
        int min_val = INT_MAX;
        int min_index = 0;

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            if (cur >= max_val) {
                max_val = cur;
                max_index = i;
            }
            if (cur < min_val) {
                min_val = cur;
                min_index = i;
            }
        }

        ans = (max_val - min_val) * 1LL * k;
       // cout << min_index << " " << max_index << endl;
        return ans;
    }
};