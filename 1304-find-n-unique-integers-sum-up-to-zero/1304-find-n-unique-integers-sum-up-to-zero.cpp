class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> ans(n);
       
        for (int i = 1; i < n ; i += 2) {
            ans[i-1] = i;
            ans[i] = -i;
        }

        return ans;
    }
};