class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        int left = k;
        int n = arr.size();
        int ma = arr[n - 1];
        int idx = 0;
        int start = 1;
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }
        for (int i = 1; i <= ma; i++) {
            if (map.find(i) == map.end()) {
                left--;
                if (left == 0)
                    return i;
            }
        }
        ans = ma;
        while (left--) {
            ans++;
        }
        return ans;
    }
};