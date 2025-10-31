class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        unordered_set<int> st;
        int x = -1;
        int y = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                if (x == -1) {
                    x = nums[i];
                } else {
                    y = nums[i];
                }
            }
            st.insert(nums[i]);
        }

        return {x, y};
    }
};