class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (const string& word : words) {
            int sum = 0;
            for (char ch : word) {
                sum += weights[(ch - 'a')];
            }

            char test = 'g';
            cout << test - 'a' << endl;
            cout << sum << endl;
            // sum = (sum % 26);
            sum = (sum % 26);
            if (sum >= 13) {
                sum = (sum - 25);
                sum = abs(sum);

            } else {
                sum = abs(25 - sum);
                sum %= 26;
            }
            ans += (sum + 'a');
            cout << sum << endl;
        }

        return ans;
    }
};