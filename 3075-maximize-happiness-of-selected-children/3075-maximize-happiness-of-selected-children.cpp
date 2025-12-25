class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        long long ans = 0;
        sort(happiness.begin(), happiness.end());
        int it = 0;
        for (int i = happiness.size() - 1; i >= 0; i--) {
            if (happiness[i] <= it)
                return ans;
            if (k == 0)
                return ans;
            ans += (happiness[i] - it);
            it++;
            k--;
        }

        return ans;
    }
};