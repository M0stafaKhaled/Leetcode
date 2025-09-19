class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
          sort(usageLimits.begin(), usageLimits.end());
        long long used = 0; 
        int groups = 0;
        for (long long x : usageLimits) {
            used += x;
            if (used >= (long long)(groups + 1) * (groups + 2) / 2) {
                groups++;
            }
        }
        return groups;
    }
};