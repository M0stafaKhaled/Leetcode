class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int ans = 0;
        int cur = 0;
        int z = 0;
        int start = 0;
        int sum = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0)
                sum += customers[i];
        }
        cout << sum << endl;
        int n = customers.size();
        for (int i = 0; i < min(minutes, n); i++) {
            if (grumpy[i] == 1)
                cur += customers[i];
        }
        ans = max(cur, ans);
        for (int i = minutes; i < customers.size(); i++) {
            if (grumpy[i - minutes] == 1)
                cur -= customers[i - minutes];

            if (grumpy[i] == 1)
                cur += customers[i];

            ans = max(cur, ans);
        }

        return ans + sum;
    }
};