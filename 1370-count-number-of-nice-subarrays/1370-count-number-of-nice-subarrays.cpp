class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // l=3   r=9  cur=2 coutner=4 -> l +1 3+1
        //  0  1 2 3 4 5 6 7 8 9
        //[2,2,2,1,2,2,1,2,2,2]
        // l=0 r =6 s=16
        //   0 0 0 l 0 0 1 x 0 r
        //   0 0 0 1 1 1 2 2 2 2
        int count = 0;
        int ans = 0;
        int sub = 0;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            count += (nums[r] & 1);
            if (count == k) {
                sub = 0;
                while (count == k) {
                    count -= (nums[l++] & 1);
                    sub++;
                }
            }
            ans += sub;
        }

        return ans;
    }
};