class Solution {
public:
    bool vist[101];
    int cost[101];

    double dfs(vector<vector<pair<int, double>>>& graph, int start, int end) {
        if (start == end)
            return 1.0;

        vist[start] = true;
        double ans = -1;
        for (int i = 0; i < graph[start].size(); i++) {
            int cur = graph[start][i].first;
            if (!vist[cur] && cost[cur] > cost[start] + 1) {
                cost[cur] = cost[start] + 1;
                double r = dfs(graph, cur, end) * graph[start][i].second;
                if (r >= 0)
                    ans = r;
            }
        }

        return ans;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, int> var_id;
        int id = 0;

        vector<vector<pair<int, double>>> graph(101);
        for (int i = 0; i < equations.size(); i++) {
            string u_str = equations[i][0];
            string v_str = equations[i][1];
            double val = values[i];

            if (!var_id.count(u_str))
                var_id[u_str] = id++;
            if (!var_id.count(v_str))
                var_id[v_str] = id++;

            int u = var_id[u_str];
            int v = var_id[v_str];

            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string start_str = queries[i][0];
            string end_str = queries[i][1];

            if (!var_id.count(start_str) || !var_id.count(end_str)) {
                ans.push_back(-1.0);
                continue;
            }

            memset(vist, 0, sizeof vist);
            memset(cost, 0x3f, sizeof cost);

            int start = var_id[start_str];
            int end = var_id[end_str];
            cost[start] = 0;

            double d = dfs(graph, start, end);
            if (d < 0)
                d = -1;
            ans.push_back(d);
        }

        return ans;
    }
};
