class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {

        unordered_set<int> st;
        vector<int> ans;
        for (int i = 0; i < bulbs.size(); i++) {
            if (st.find(bulbs[i]) != st.end())
                st.erase(bulbs[i]);
            else
                st.insert(bulbs[i]);
        }

        for (int i = 0; i < bulbs.size(); i++) {
            if (st.find(bulbs[i]) != st.end()) {
                ans.push_back(bulbs[i]);
                st.erase(bulbs[i]);
            }
        }

        sort(ans.begin() , ans.end()) ; 
        return ans;
    }
};