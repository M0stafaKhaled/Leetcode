class Solution {
public:
    void sortByColumn(vector<vector<int>>& v, int col) {
        sort(v.begin(), v.end(),
             [col](const vector<int>& a, const vector<int>& b) {
                 return a[col] < b[col];
             });
    }
    bool carPooling(vector<vector<int>>& trips, int k) {

        sortByColumn(trips, 1);

        for (int i = 0; i < trips.size(); i++) {
            int cur = trips[i][0];
            int end = trips[i][2];
            int ex = end ; 
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            pq.push({end, cur});
            while (i + 1 < trips.size() && ex >= trips[i + 1][1]) {
                cur += trips[i + 1][0];
            
                while (pq.size() && trips[i + 1][1] >= pq.top().first) {
                 //    cout << "pq " << pq.top().second << endl;
                     cur -= pq.top().second;
                    pq.pop();
                }
                end = trips[i + 1][2];
                ex = max(ex , end) ; 
                 if (cur > k)
                    return 0;
                pq.push({end, trips[i + 1][0]});
                i++;
              
            }
            cout << cur << endl;
            if (cur > k)
                return 0;
        }

        return 1;
    }
};