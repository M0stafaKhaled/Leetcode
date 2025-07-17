class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;

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
                    st.pop();
                continue;
            }
            st.push(cur);
            cout << cur << endl;
        }

        if (st.empty())
            return "/";

        stack<string> st2;

        while (st.size()) {
            st2.push(st.top());
            st.pop();
        }
        string ans = "";
        while (st2.size()) {
            ans += st2.top();
            st2.pop();
        }
        return ans;
    }
};