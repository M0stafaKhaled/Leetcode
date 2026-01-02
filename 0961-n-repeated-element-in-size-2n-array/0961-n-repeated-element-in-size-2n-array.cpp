class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        unordered_map<int, int> map;
        int n = nums.size();
        n /= 2;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        for (auto e : map) {
            if (e.second == n)
                return e.first;
        }

        return 0;
    }
};