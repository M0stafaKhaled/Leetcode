class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(), players.end());
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < trainers.size(); i++) {

            pq.push(trainers[i]);
        }

        for (int i = 0; i < players.size(); i++) {

            if(pq.empty()) return ans ; 

            while(pq.size() && players[i] > pq.top()) pq.pop() ; 

            if(pq.empty()) return ans ; 

            ans++;
            pq.pop() ; 
        }

        return ans ; 
    }
};