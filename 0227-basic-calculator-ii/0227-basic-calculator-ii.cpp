class Solution {
public:
    int calculate(string cur) {

        stack<int> st;
        string s = "";
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] != ' ')
                s += cur[i];
        }
        char x = '+';
        for (int i = 0; i < s.size(); i++) {
            int num = 0;
            while (i < s.size() && s[i] - '0' < 10 && s[i] - '0' >= 0) {
                int dd = s[i] - '0';

                num = num * 10;
                num += s[i] - '0';
                i++;
            }
    
            if (x == '+') {
                st.push(num);
            } else if (x == '-') {
                st.push(-num);
            } else if (x == '/') {
                int top = st.top();
                st.pop();
                st.push(top / num);
            } else {
                int top = st.top();
                st.pop();
                st.push(top * num);
            }
            if (i  >= s.size())
                break;
           
            x = s[i];
            
        }

        int ans = 0;
        while (st.size()) {
            int top = st.top();
            st.pop();

            ans += top;
        }
        return ans;
    }
};