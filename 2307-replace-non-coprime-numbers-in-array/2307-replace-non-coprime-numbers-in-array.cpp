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

    int lcm(long long a, long long b, int gcd) { return (a * b) / gcd; }
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
            int z = gcd(a, b);
            while (z > 1) {

                if (st.size() >= 1) {
                    int r = lcm(a, b, z);
                    a = st.top();
                    st.pop();
                    b = r;
                    z = gcd(a, b);

                } else {
                    b = lcm(a, b, z);
                    z = gcd(a, b);
                    f = 1;
                    break;
                }

                f = 1;
            }
            if (z == 1) {
                st.push(a);
                st.push(b);
            } else {
                st.push(b);
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
            int z = gcd(a, b);
            if (z > 1) {
                st.pop();
                st.push(lcm(a, b, z));
            } else {
                ans.push_back(a);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};