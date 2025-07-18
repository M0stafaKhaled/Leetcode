class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;

        for (int i = 0; i < rating.size(); i++) {
            for (int j = i + 1; j < rating.size(); j++) {

                for (int k = j + 1; k < rating.size(); k++) {
                    int a = rating[i];
                    int b = rating[j];
                    int c = rating[k];
                    if (a > b && b > c)
                        ans++;
                    if (c > b && b > a)
                        ans++;
                }
            }
        }

        return ans;
    }
};