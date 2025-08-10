class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        unordered_set<string> st;
        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            string cur = to_string(power);
            sort(cur.begin(), cur.end());
            st.insert(cur);
        }
        string cur = to_string(n);
        sort(cur.begin(), cur.end());

        return st.find(cur) != st.end();
    }
};