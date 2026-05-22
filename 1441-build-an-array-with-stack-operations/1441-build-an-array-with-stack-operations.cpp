class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> ans;
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (start == target.size())
                break;
            while (target[start] > i) {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            ans.push_back("Push");
            start++;
        }

        return ans;
    }
};