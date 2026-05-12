class Solution {
public:
    int minimumEffort(vector<vector<int>>& arr) {
        int n = arr.size();

        vector<pair<int, int>> tasks;

        for (int i = 0; i < n; i++) {
            int actual = arr[i][0];
            int minimum = arr[i][1];

            tasks.push_back({minimum - actual, i});
        }

        sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        int ans = 0;
        int energy = 0;

        for (int i = 0; i < n; i++) {
            int index = tasks[i].second;

            int actual = arr[index][0];
            int minimum = arr[index][1];

            if (energy < minimum) {
                int need = minimum - energy;
                ans += need;
                energy += need;
            }

            energy -= actual;
        }

        return ans;
    }
};