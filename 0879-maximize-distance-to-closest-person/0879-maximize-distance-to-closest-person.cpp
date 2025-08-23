class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 1;
        int prev = -1;
        int next = -1;
        vector<int> nexts(seats.size());
        nexts[nexts.size() - 1] = -1;
        if (seats.back() == 1) {
            nexts[nexts.size() - 1] = nexts.size() - 1;
        }

        for (int i = seats.size() - 2; i >= 0; i--) {
            if (seats[i + 1] == 1) {
                nexts[i] = i + 1;
            } else {
                nexts[i] = nexts[i + 1];
            }
        }

        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 0) {
                int a = i - prev;
                int b = nexts[i] - i;
                if (nexts[i] == -1) {
                    b = a;
                }
                if(prev ==-1) a =b ; 
                int cur = min(a, b);
                ans = max(cur, ans);
            }
            if (seats[i] == 1) {
                prev = i;
            }
        }

        return ans;
    }
};