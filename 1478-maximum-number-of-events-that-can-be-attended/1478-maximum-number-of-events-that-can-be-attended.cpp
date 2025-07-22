class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0;

        sort(events.begin(), events.end());
        int start = events[0][0];
        int end = events[events.size() - 1][1];
        int day = events[0][0];
        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 0;
      //  cout<<end<<endl ; 
        for (int i = start;  pq.size() || idx<events.size() ; i++) {

            while (idx < events.size() && events[idx][0] <= i) {
              //  cout<<"pushed: "  << events[idx][1] << endl ; 
                pq.push(events[idx][1]);
                idx++;
            }

            while (pq.size() && pq.top() < i)
             {
              //   cout<<"poped: "  << pq.top() << endl ; 
                   pq.pop();
             }

            if (pq.size() && pq.top() >= i) {
              //  cout<<"poped2: "  << pq.top() << "i " << i  << endl ; 
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};

