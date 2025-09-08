class Solution {
public:
    int re(int num) {

        int ans = 0;
        while (num) {
            ans += num % 10;
            num /= 10;
            if (num)
                ans *= 10;
        }

        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            st.insert(re(nums[i]));
        }

        return st.size();
    }
};