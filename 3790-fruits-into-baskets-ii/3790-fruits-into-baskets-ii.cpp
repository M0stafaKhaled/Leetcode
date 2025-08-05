class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int idx = 1;
        int ans = baskets.size();
        unordered_set<int> st;
        for (int i = 0; i < fruits.size(); i++) {

            int cur = fruits[i];
            for (int j = 0; j < baskets.size(); j++) {
                int des = baskets[j];
                if (st.find(j) != st.end())
                    continue;
                if (des >= cur) {
                    ans--;
                    st.insert(j);
                    break;
                }
            }
        }

        return ans;
    }
};