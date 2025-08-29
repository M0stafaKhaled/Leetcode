class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {

            map[nums[i]]++;
        }

        for (auto e : map) {
            int a = e.first + k;
            if (map.find(a) != map.end()) {
                int x = (e.second * map[a]);

                ans += x;
            }
        }

        return ans;
    }
};