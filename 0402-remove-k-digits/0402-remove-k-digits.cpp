class Solution {
public:
    string removeKdigits(string num, int k) {
        // 129
        // 192
        // 1927
        if (k == num.size())
            return "0";
        string ans = "";

        for (int i = 0; i < num.size(); i++) {
            if (ans.empty()) {
                ans += num[i];
                continue;
            }

            while (ans.size() && ans.back() > num[i] && k) {
                // cout<<ans.back() << " " << num[i]  << endl;
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }

        while (k--) {
            ans.pop_back();
        }

        string ans2 = " ";

        int start = 0;
        while (start < ans.size() && ans[start] == '0')
            start++;
        if (start == ans.size())
            return "0";

        return ans.substr(start);

        return ans;
    }
};