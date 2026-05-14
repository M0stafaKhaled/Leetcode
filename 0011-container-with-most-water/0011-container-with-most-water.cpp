class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0;
        int end = n - 1;

        int cur = 0;
        int ans = 0;

        while (end > st) {
            if (height[st] >= height[end]) {
                cur = ((end - st)) * min(height[st], height[end]);
                end--;
            } else {
                cur = ((end - st)) * min(height[st], height[end]);
                st++;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};