class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int a = 0;
        int b = 0;

        int ans = INT_MAX;

        while (a < nums1.size() && b < nums2.size()) {

            int cur1 = nums1[a];
            int cur2 = nums2[b];

            if (cur1 > cur2) {
                b++;
            } else if (cur2 > cur1) {
                a++;
            } else {
                return cur1;
            }
        }

        return -1;
    }
};