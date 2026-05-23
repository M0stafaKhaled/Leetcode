class Solution {
public:
    bool check(vector<int>& nums) {
        int end = 0;
        int mins = INT_MAX;
        int start = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mins) {

                if (mins != nums[i])
                    start = i;
                mins = nums[i];
                end = i;
            }
            freq[nums[i]]++;
        }
        if (freq[mins] > ((nums.size() + 1) / 2))
            return true;
        bool check1 = true;
        bool check2 = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            int cur = (i + end) % nums.size();
            int next = (i + end + 1) % nums.size();
            if (nums[cur] > nums[next]) {
                check1 = false;
                break;
            }
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            int cur = (i + start) % nums.size();
            int next = (i + start + 1) % nums.size();
            if (nums[cur] > nums[next]) {
                check2 = false;
                break;
            }
        }
        return check2 | check1;
    }
};