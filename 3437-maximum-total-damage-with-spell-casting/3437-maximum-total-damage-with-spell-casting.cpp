class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<int, long long> map;
        vector<int> values;
        for (int i = 0; i < power.size(); i++) {
            map[power[i]] += power[i];
        }
        for (auto e : map) {
            values.push_back(e.first);
        }
        vector<long long> db(values.size(), 0);
        sort(values.begin(), values.end());
        for (int i = 0; i < values.size(); i++) {
            long long currentDamage = map[values[i]];
            int j = i - 1;
            while (j >= 0 && values[i] - values[j] <= 2) {
                j--;
            }

            if (j >= 0) {
                currentDamage += db[j];
            }

            long long skip = (i > 0) ? db[i - 1] : 0;
            db[i] = max(currentDamage, skip);
        }
        return db[values.size() - 1];
    }
};