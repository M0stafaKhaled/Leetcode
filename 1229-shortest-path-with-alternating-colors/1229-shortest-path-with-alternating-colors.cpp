class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {

        vector<int> ans(n, 1e9);
      
        ans[0] = 0;
        vector<vector<int>> graph1(n);
        vector<vector<int>> graph2(n);
        for (int i = 0; i < redEdges.size(); i++) {
            int first = redEdges[i][0];
            int second = redEdges[i][1];

            graph1[first].push_back(second);
        }
        for (int i = 0; i < blueEdges.size(); i++) {
            int first = blueEdges[i][0];
            int second = blueEdges[i][1];

            graph2[first].push_back(second);
        }
        queue<pair<int,  pair<int  , int>>> q;
        for (auto e : graph1[0]) {
            q.push({e, {1 , 1}});
            if (e != 0)
                ans[e] = 1;
        }
        for (auto e : graph2[0]) {
          q.push({e, {0 , 1}});
            if (e != 0)
                ans[e] = 1;
        }
        int h = 2;
        while (q.size()) {
            auto [node, vv] = q.front();
            auto [color , val] = vv ; 
            
            int cur = ans[node];
            int size = q.size();
            q.pop();
            // cout << node << " " << color << " " << cur << endl;

            while (size--) {
                if (color == 1) {
                    for (auto& e : graph2[node]) {

                        //  cout << e << endl;
                        if (e != -1) {
                            cout << e << " " << ans[e] << " " << h << endl;
                            q.push({e, {0, val+1}});
                            ans[e] = min(ans[e], val+1);
                            e = -1;
                        }
                    }
                } else {
                    for (auto& e : graph1[node]) {

                        if (e != -1) {
                            cout << e << " " << ans[e] << endl;
                              q.push({e, {1, val+1}});
                            ans[e] = min(ans[e], val+1);
                            e = -1;
                        }
                    }
                }

                // cout << "end" << endl;
            }
            h++;
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == 1e9)
                ans[i] = -1;
        }

        return ans;
    }
};