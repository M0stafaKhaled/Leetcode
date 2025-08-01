class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> st;
        int ans = 0;
        int start = 0;
        int cur = 0;
        unordered_set<int> prev;
        for (int i = 0; i < arr.size(); i++) {
            unordered_set<int> cur;
            cur.insert(arr[i]);
            for (auto e : prev) {
                for (auto c : cur) {
                    cur.insert(c | e);
                }
            }

            prev = cur;
            for (auto e : cur)
                st.insert(e);
        }

        return st.size();
    }
};