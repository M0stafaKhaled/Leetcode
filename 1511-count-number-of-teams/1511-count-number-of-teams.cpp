class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;

        for (int j = 1; j < rating.size(); j++) {

            int cur = rating[j];
            int left = 0;
            int right = 0;

            int left2 = 0;
            int right2 = 0;
            for (int i = j - 1; i >= 0; i--) {
                if (rating[i] < cur)
                    left++;
                if (rating[i] > cur)
                    left2++;
            }
            for (int i = j + 1; i < rating.size(); i++) {
                if (rating[i] > cur)
                    right++;
                if (rating[i] < cur)
                    right2++;
            }

            ans += (right * left);
            ans += (right2 * left2);
        }
        return ans;
    }
};