class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);

        // Populate the graph
        for (int i = 0; i < flights.size(); ++i) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            graph[from].push_back({to, price});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            q;
        q.push({0, 0, src});
        vector<int> dist(n + 1, 1e9);
        dist[src] = 0;
        vector<int> paths(n + 1, 1e9);
        // paths[src] = 0;
        int l = 0;
        while (!q.empty()) {
            int sz = q.size();
            l++;

            auto [val, path, node] = q.top();
            q.pop();

            if (node == dst)
                return val;
            if (path > k || path >= paths[node])
                continue;
            paths[node] = path;
            for (int i = 0; i < graph[node].size(); i++) {
                cout << "Test" << endl;
                int ch = graph[node][i].first;
                int f = graph[node][i].second;

                // paths[ch] = path + 1;
                q.push({(val + f), path + 1, ch});
                dist[ch] = val + f;
            }
        }

        return -1;
    }
};