class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        unordered_set<int> st;
        int cur = 0;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (st.size() && st.find(nums[i]) != st.end()) {
                int v = nums[start++];
                cur -= v;
                st.erase(v);
            }

            st.insert(nums[i]);
            cur += nums[i];
            ans = max(ans, cur);
        }

        return ans;
    }
};