class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int re = 1e9;
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int a = nums[i];
            int j = i + 1;
            int k = nums.size() - 1;

            while (k > j) {

                int b = nums[j];
                int c = nums[k];
                int z = a + b + c;
                z = abs(z - target);
                if (z < re) {
                    ans = a + b + c;
                    re = z;
                }
                if(a+b+c > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }

            }
        }

        return ans;
    }
};