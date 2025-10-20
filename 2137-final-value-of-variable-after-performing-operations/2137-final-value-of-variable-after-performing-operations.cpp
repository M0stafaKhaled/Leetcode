class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        int ans = 0;

        for (int i = 0; i < operations.size(); i++) {
            for (char e : operations[i]) {
                if (e == '-') {
                    ans--;
                    break;
                } else if (e == '+') {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};