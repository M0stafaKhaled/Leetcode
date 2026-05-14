class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int start = 0;
        int end = people.size() - 1;
        // 1245
        // 3345
        while (end >= start) {
            ans++;

            int cur = people[end];
            if (end > start && (cur + people[start]) <= limit) {
                cur += people[start];
                start++;
            }

            end--;
        }

        return ans;
    }
};