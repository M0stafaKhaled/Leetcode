class Solution {
public:
    struct Edge {
        int to;
        long long cost;
    };

    int n;
    long long limitK;
    vector<bool> onlineNodes;
    vector<vector<Edge>> graph;
    vector<int> topo;

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        limitK = k;
        onlineNodes = online;

        graph.assign(n, {});
        vector<int> indegree(n, 0);

        long long maxCost = 0;

        buildGraph(edges, indegree, maxCost);
        buildTopologicalOrder(indegree);

        long long low = 0;
        long long high = maxCost;
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canAchieveScore(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }

private:
    void buildGraph(vector<vector<int>>& edges, vector<int>& indegree, long long& maxCost) {
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            long long cost = e[2];

            graph[u].push_back({v, cost});
            indegree[v]++;

            maxCost = max(maxCost, cost);
        }
    }

    void buildTopologicalOrder(vector<int> indegree) {
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto& edge : graph[u]) {
                int v = edge.to;
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    bool canAchieveScore(long long score) {
        const long long INF = 4e18;

        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) {
                continue;
            }

            for (auto& edge : graph[u]) {
                int v = edge.to;
                long long cost = edge.cost;

                if (cost < score) {
                    continue;
                }

                if (v != n - 1 && !onlineNodes[v]) {
                    continue;
                }

                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                }
            }
        }

        return dist[n - 1] <= limitK;
    }
};