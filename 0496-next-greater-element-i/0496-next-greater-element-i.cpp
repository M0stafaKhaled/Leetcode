class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> stk;
        int n = nums2.size();
        unordered_map<int, int> map;

        for (int i = n - 1; i >= 0; i--) {
            if (stk.empty()) {
                stk.push(nums2[i]);

                map[nums2[i]] = -1;
                continue;
            }

            while (stk.size() && stk.top() < nums2[i]) {
                stk.pop();
            }

            if (stk.size())
                map[nums2[i]] = stk.top();
            else
                map[nums2[i]] = -1;

            stk.push(nums2[i]);
        }

        int n2 = nums1.size();
        vector<int> ans(n2);
        for (int i = 0; i < n2; i++) {
            ans[i] = map[nums1[i]];
        }

        return ans;
    }
};