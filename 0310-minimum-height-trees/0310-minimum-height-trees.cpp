class Solution {
public:
    vector<int> in;
    void dfs(vector<vector<int>>& graph, int node) {
        in[node]++;
        for (auto ch : graph[node]) {
            if (in[ch] > 0) {
                in[ch]++;
                continue;
            }
            //   in[node]++;
            dfs(graph, ch);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<vector<int>> graph(n);
        in = vector<int>(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            in[u]++;
            in[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        //    dfs(graph, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            //  cout << in[i] << " ";
            if (in[i] == 1) {
                q.push(i);
            }
        }
        int temp = n;
        while (n > 2) {
            int sz = q.size();
            n -= sz;
            for (int i = 0; i < sz; i++) {
                int cur = q.front();

                q.pop();

                for (auto ch : graph[cur]) {
                    --in[ch];
                    if (in[ch] == 1)
                        q.push(ch);
                }
            }
        }
        vector<int> ans;

        while (q.size()) {
            int cur = q.front();
            cout << in[cur] << " ";
            // cout << cur << " ";
            ans.push_back(cur);
            q.pop();
        }
        // for(int i =0 ; i<temp ; i++)
        // {
        //     if(in[i] ==1)
        // }
        return ans;
    }
};