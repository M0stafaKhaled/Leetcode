class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int> in(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            in[v]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};