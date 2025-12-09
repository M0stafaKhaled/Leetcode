class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            if (stk.empty()) {
                stk.push(i);
                continue;
            }

            while (stk.size() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }

            if (stk.size()) {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }

        return ans;
    }
};