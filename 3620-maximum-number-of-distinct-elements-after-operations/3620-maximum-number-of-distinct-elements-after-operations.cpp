class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 1;

        unordered_map<long long, int> map;
        sort(nums.begin(), nums.end());
        int start = -k;
        int f = nums[0] + start;
        for (int i = 1; i < nums.size(); i++) {
            long long next = f + 1;
            long long cur = next - nums[i];
         //   cout << cur << endl;
            int j = next;
            bool check = false;
            for (; j <= nums[i] + k; j++) {
                cur = j - nums[i];
                if (cur <= k && cur >= -k) {
                    ans++;
                    check = true;
                    break;
                }
            }

            if (check)
                f = j;
        }

        return ans;
    }
};