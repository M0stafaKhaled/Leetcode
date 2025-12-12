class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
            return s.size();
        int start = 0;
        int ans = 0;
        unordered_map<char, int> arr;
        for (int i = 0; i < s.size(); i++) {
            char cur = s[i];
            arr[cur]++;
            while (i > start && arr[cur] > 1) {
                arr[s[start]]--;
                start++;
            }

            ans = max(ans, (i - start) + 1);
        }

        return ans;
    }
};