class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<int, int> map, vist;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            vist[nums[i]] = 0;
        }

        int ans = 0;
        for (auto e : map) {
            int nums = e.first;
            int cur = 1;

            while (nums > 1) {
                int child = sqrt(nums);
                if (map.find(child) == map.end())
                    break;
                if (child * child != nums)
                    break;
                if (map[child] < 2)
                    break;
                cur += 2;
                nums = sqrt(nums);
            }
            if (e.first == 1) {
                cur = max(cur, e.second - (e.second % 2 == 0));
            }
            ans = max(ans, cur);
        }

        return ans;
    }
};