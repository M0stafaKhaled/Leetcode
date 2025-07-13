class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        int j = 0;
        for (int i = 0; i < players.size(); i++) {
            if (j == trainers.size())
                return ans;
            while (j < trainers.size() && players[i] > trainers[j])
                j++;
            if (j >= trainers.size())
                return ans;
            j++;
            ans++;
        }

        return ans;
    }
};