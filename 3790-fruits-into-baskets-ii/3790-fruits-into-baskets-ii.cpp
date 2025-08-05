class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int idx = 1;
        int ans = baskets.size();
        vector<bool>vist(ans) ; 
        for (int i = 0; i < fruits.size(); i++) {
            int cur = fruits[i];
            for (int j = 0; j < baskets.size(); j++) {
                int des = baskets[j];
                if (vist[j])
                    continue;
                if (des >= cur) {
                    ans--;
                    vist[j] = 1 ;
                    break;
                }
            }
        }

        return ans;
    }
};