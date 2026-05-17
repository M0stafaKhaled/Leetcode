class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        //   unordered_map<int, int> freq;

        int max_f = 0;
        int max_e = 0;
        int ans = 0;
        int start = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> freq;

            for (int j = i; j < nums.size(); j++) {
                int len = (j - i) + 1;
                freq[nums[j]]++;
                if (freq[target] > len / 2) {
                    ans++;
                }
            }
            cout << freq[target] << endl;
        }
        return ans;
    }
};