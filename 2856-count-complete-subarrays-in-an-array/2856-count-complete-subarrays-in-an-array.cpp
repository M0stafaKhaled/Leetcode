class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        if (st.size() == nums.size())
            return 1;

        unordered_map<int, int> st2;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            st2[nums[i]]++;
           
            while (st.size() == st2.size()) {
                st2[nums[start]]--;
                if (st2[nums[start]] == 0)
                    st2.erase(nums[start]);

                start ++;
            }
            ans+=start ; 
        }
        return ans ; 
    }
};