class Solution {
public:
    int arr[32];
    vector<int> smallestSubarrays(vector<int>& nums) {
        int mor = 0;
        vector<int> suf(nums.size() + 1);
        int end = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            mor |= nums[i];
            suf[end] |= suf[end + 1] | nums[end];
            end--;
        }

        vector<int> ans(nums.size());
        int start = -1;
        end = 0;

        int bit1 = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (start >= 0) {
                for (int j = 0; j < 30; j++) {
                    if (arr[j] == 1 && (nums[start] >> j) & 1)
                        bit1 ^= (1 << j);

                    arr[j] -= (nums[start] >> j) & 1;
                }
                //  cout << "test 2: " << bit1 << endl;
            }
            while (end < nums.size() && bit1 != suf[i]) {
                int cur = nums[end];
                for (int j = 0; j < 30; j++) {

                    arr[j] += ((cur >> j)) & 1;

                    //  cout<<((cur >> j) & 1) <<" ";
                    if (arr[j] >= 1)
                        bit1 |= (1 << j);
                }
                if (bit1 == suf[i]) {

                    //  ans[i] = end - i + 1;
                    end++;
                    break;
                }
                if (end == nums.size() - 1) {
                    
                    end++;
                    break;
                }
                end++;
                cur = nums[end];
            }

            cout << "test1: " << end << " " << bit1 << endl;

            start = i;
            ans[i] = max((end - i) , 1);
        }

        return ans;
    }
};