class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.empty()) {
                st.push(nums[i]);
                continue;
            }
            int a = st.top();
            st.pop();
            int b = nums[i];
            bool f = false;
            while (gcd(a, b) > 1) {

                if (st.size() >= 1) {
                    int r = lcm(a, b);
                    a = st.top();
                    st.pop();
                    b = r;

                } else {
                    b = lcm(a, b);
                    f = 1;
                    break;
                }

                f = 1;
            }
            if (gcd(a, b) == 1) {
                st.push(a);
                st.push(b);
            } else {
                st.push(b);
            }
            if (!f) {
            }
        }

        // if (st.size() == 1)
        //     return {st.top()};

        while (st.size()) {

            if (st.size() == 1) {
                ans.push_back(st.top());
                reverse(ans.begin(), ans.end());
                return ans;
            }

            int a = st.top();
            st.pop();
            int b = st.top();
            if (gcd(a, b) > 1) {
                st.pop();
                st.push(lcm(a, b));
            } else {
                ans.push_back(a);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};