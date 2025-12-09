class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        // recangle (i -j) * min(h(i , j))
        // 2,1,5,6,2,3

        // 0=>2
        // calc(0,1) 2
        // 1=>1
        // 1=>1 , 2=>5
        // 1=>1 , 2=>5  3=>6
        nums.push_back(INT_MIN);
        int ans = 0;
        stack<pair<int, int>> stk;
        for (int i = 0; i < nums.size(); i++) {

            int start = i;
            while (stk.size() && stk.top().second > nums[i]) {
                auto [top, val] = stk.top();
                stk.pop();
                start = top;
                int width = i - top;
                ans = max(ans, width * val);
            }

            stk.push({start, nums[i]});
        }

        return ans;
    }
};