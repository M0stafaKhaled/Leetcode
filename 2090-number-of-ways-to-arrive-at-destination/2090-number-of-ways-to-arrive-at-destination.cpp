class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> graph(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, 0});
        vector<long long> costs(n, LLONG_MAX);
        vector<long long> paths(n, 0);
        costs[0] = 0;
        paths[0] = 1;
        const int mode = 1e9 + 7;
        for (int i = 0; i < roads.size(); i++) {
            int node = roads[i][0];
            int time = roads[i][2];
            int v = roads[i][1];
            graph[node].push_back({v, time});
            graph[v].push_back({node, time});
        }

        while (pq.size()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (costs[node] < cost)
                continue;
            for (auto ch : graph[node]) {
                auto [ch_node, ch_cost] = ch;
                long long d = (ch_cost + cost);

                if (costs[ch_node] < d)
                    continue;

                if (costs[ch_node] == d) {
                    paths[ch_node] += paths[node];
                    paths[ch_node] %= mode;
                    continue;
                }
             //   cout << ch_node << endl;
                costs[ch_node] = ch_cost + cost;
                paths[ch_node] = paths[node];
             //   paths[ch_node] %= mode;
                pq.push({costs[ch_node], ch_node});
            }
        }

        return paths[n - 1] % mode;
    }
};