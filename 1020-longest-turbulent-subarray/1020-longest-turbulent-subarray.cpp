class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1)
            return 1;
        vector<int> pre(arr.size());

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                pre[i] = 0;
            } else if (arr[i] > arr[i + 1]) {
                pre[i] = 1;
            } else {
                pre[i] = -1;
            }
        }

        int ans = 0;

        for (int i = 0; i < pre.size(); i++) {
            if(pre[i] == -1) continue ; 
            if (i == pre.size() - 1)
                break;
            int cur = 2;

            while (i + 1 < pre.size()-1 && pre[i] != pre[i + 1] && pre[i] != -1 &&
                   pre[i + 1] != -1) {
                cur++;
                i++;
            }

            ans = max(cur, ans);
        }

        return max(ans, 1);
    }
};