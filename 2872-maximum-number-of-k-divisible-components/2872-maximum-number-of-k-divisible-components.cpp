class Solution {
public:
int target;
    vector<vector<int>> graph ; 
    vector<bool> visted ; 
    int ans ; 
    long long  solve(int cur  , vector<int>& values )
    {
        long long sum =values[cur];
        visted[cur] = true ; 
        for(auto child : graph[cur])
        {
            if(!visted[child])
           sum+=solve(child  , values);
           sum%=target; 
        }

        if(sum%target ==0) ans++;
        return sum ; 
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        graph.resize(n);
        visted.resize(n);
         target = k ; 
        for(int i =0 ; i<edges.size() ; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
              graph[edges[i][1]].push_back(edges[i][0]);
        }

    solve(0  , values);
        return ans ; 
    }
};