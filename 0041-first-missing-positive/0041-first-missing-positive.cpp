class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > nums.size()) {
                nums[i] = 0;
                continue;
            }
            int d = nums[i];
            nums[start] = d;
            if (i != start)
                nums[i] = 0;
            start++;
        }
        // cout << "enddd " << endl;

        for (int i = 0; i < start; i++) {
            int x = nums[i];
            while (x > 0 && x <= n && nums[x - 1] != x) {
                swap(nums[i], nums[x - 1]);
                x = nums[i];
            }
            // cout << nums[i] << endl;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != i + 1)
                return i + 1;
        }

        return nums.size() + 1;
    }
};