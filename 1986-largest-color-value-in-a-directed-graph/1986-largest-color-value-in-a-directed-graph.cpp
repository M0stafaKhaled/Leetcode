class Solution {
public:
    int ans[26];
    vector<int> instack;
    int db[100000][26];
    bool valid = true;
    string s;

    void dfs(vector<vector<int>>& graph, int node) {
        cout<<node <<endl; 
        if (instack[node] == 1) {
            valid = false;
            return;
        }
         if (instack[node] == 2)
            return;
       
        instack[node] = 1;
        int cur = s[node] - 'a';

        for (int i = 0; i < graph[node].size(); i++) {
            int child = graph[node][i];
            int child_char = s[child] - 'a';

            dfs(graph, child);
            for (int j = 0; j < 26; j++) {
                db[node][j] = max(db[node][j], db[child][j]);
            }
        }
        instack[node] = 2;

        db[node][cur] += 1;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        s = colors;
        int n = colors.size();
        if(n ==0) return 0 ; 
        if(edges.size() ==0)  return 1 ; 
        // memset(db, -1, sizeof db);
        vector<vector<int>> graph(n + 3);
        instack = vector<int>(n + 1, 0);
        vector<int> dgree(n + 3, 0);
        for (int i = 0; i < edges.size(); i++) {

            dgree[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
        }

        int ans_val = 0;
        int counter = 0;
        for (int i = 0; i < n; i++) {

            if (!valid) {
                return -1;
            }
            if (dgree[i] == 0 && graph[i].size() ) {

                counter++;
                instack[i] = 0;

                dfs(graph, i);
            }
        }
      

        if (counter == 0 || !valid) {

            return -1;
        }

        for (int j = 0; j < n; j++)
            for (int i = 0; i < 26; i++) {

                ans_val = max(db[j][i], ans_val);
            }

        return ans_val;
    }
};