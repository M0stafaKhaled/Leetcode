class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {

        vector<vector<int>> lps(groups.size());

        for (int i = 0; i < groups.size(); i++) {

            vector<int> cur(groups[i].size(), 0);
            int start = 0;
            for (int j = 1; j < groups[i].size(); j++) {
                if (groups[i][j] == groups[i][start]) {
                    cur[j] = (start) + 1;
                    start++;
                } else {

                    while (start) {
                        if (groups[i][j] == groups[i][start]) {
                            cur[j] = (start) + 1;
                            start++;
                            break;
                        }
                        start--;
                    }
                }
            }

            lps[i] = cur;
        }
        int j = 0;
        for (int i = 0; i < lps.size(); i++) {
            int a = 0;
            int b = 0;

            for (; j < nums.size(); j++) {
                if (a == groups[i].size()) {
                    break;
                }
                if (nums[j] == groups[i][a]) {
                    a++;
                } else {
                    if (a == 0)
                        continue;

                    while (a) {
                        a = lps[i][a - 1];
                        if (nums[j] == groups[i][a]) {
                            a++;
                            break;
                        }
                    }
                }
            }

            if (a != groups[i].size()) {
              
                return 0;
            }
        }

        return true;
    }
};