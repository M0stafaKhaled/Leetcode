class Solution {
public:
    class DSU {
    public:
        int n;
        vector<int> pr;
        DSU(int d) {
            n = d;
            pr.resize(n);
            for (int i = 0; i < pr.size(); i++) {
                pr[i] = i;
            }
        }

        int find(int x) {
            if (pr[x] == x)
                return x;

            return pr[x] = find(pr[x]);
        }

        void con(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py)
                return;

            pr[py] = pr[px];
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // index => vector<>
        DSU dsu(accounts.size());
        unordered_map<string, int> map;
       
        vector<vector<string>> ans ; 
        for (int j = 0; j < accounts.size(); j++) {
            for (int i = 1; i < accounts[j].size(); i++) {
                if (map.find(accounts[j][i]) == map.end()) {
                    map[accounts[j][i]] = j;
                }
                else
                {
                    dsu.con(j ,map[accounts[j][i]]);
                }
            }
        }
       unordered_map<int , vector<int>> parnts ; 
        for(int i =0 ; i<accounts.size() ;i++)
        {
            parnts[dsu.find(i)].push_back(i) ; 
        }
        for(auto idxs : parnts)
        {
            set<string> st ; 
            for(auto idx : idxs.second)
            {
                for(int i =1 ; i<accounts[idx].size() ; i++)
                {
                    st.insert(accounts[idx][i]) ; 
                }
            }
            vector<string> te ; 
            int f = idxs.second[0]; 
            te.push_back(accounts[f][0]); 
            for(auto e : st)
            {
                te.push_back(e) ; 
            }
            ans.push_back(te) ; 
        }
        return ans;
    }
};