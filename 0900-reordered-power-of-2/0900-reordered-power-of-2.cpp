class Solution {
public:
    bool is_po(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }

        return count == 1;
    }
    bool reorderedPowerOf2(int n) {
        unordered_set<string> st;
        for (long long i = 1; i <= 1e9; i *= 2) {
            string cur = to_string(i);
            sort(cur.begin(), cur.end());
            st.insert(cur);
        }
        string cur = to_string(n);
        sort(cur.begin(), cur.end());

        return st.find(cur) != st.end();
    }
};