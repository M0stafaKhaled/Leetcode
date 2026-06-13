class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (const string& word : words) {
            int sum = 0;
            for (char ch : word) {
                sum += weights[(ch - 'a')];
            }

            sum = (sum % 26);
            sum = abs(25 - sum);
            ans += (sum + 'a');
        }

        return ans;
    }
};