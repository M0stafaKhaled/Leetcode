class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        for (int i = 0; i < path.size(); i++) {
            string cur = "";
            cur += path[i];

            while (i + 1 < path.size() && path[i + 1] != '/') {
                cur += path[i + 1];
                i++;
            }
            if (cur == "/")
                continue;
            if (cur == "/.")
                continue;
            if (cur == "/..") {
                if (st.size())
                    st.pop_back();
                continue;
            }
            st.push_back(cur);
        }

        if (st.empty())
            return "/";

        string ans = "";

        for (int i = 0; i < st.size(); i++) {
            ans += st[i];
        }

        return ans;
    }
};