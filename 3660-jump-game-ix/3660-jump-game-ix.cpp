class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};

        vector<int> prefixMax(n), suffixMin(n), result(n);

        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);

        result[n - 1] = prefixMax[n - 1];
        for (int i = n - 2; i >= 0; --i)
            result[i] = (prefixMax[i] > suffixMin[i + 1]) ? result[i + 1]
                                                          : prefixMax[i];

        return result;
    }
};