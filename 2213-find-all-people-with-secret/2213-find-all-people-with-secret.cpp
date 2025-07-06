class Solution {
public:
    class DSU {
    public:
        vector<int> pr;

        vector<int> size;

        DSU(int n) {
            pr.resize(n);
            size = vector<int>(n, 1);

            for (int i = 0; i < n; i++)
                pr[i] = i;
        }

        int find(int x) {
            if (x == pr[x])
                return x;

            return pr[x] = find(pr[x]);
        }

        void con(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py)
                return;
            if (size[px] < size[py]) {
                swap(px, py);
            }
            pr[py] = px;
            size[px] += size[py];
        }
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

        DSU dsu(n);
        dsu.con(0 , 0) ; 
        dsu.con(0, firstPerson);
        std::sort(meetings.begin(), meetings.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      return a[2] < b[2];
                  });

        int i = 0;
      
        for (; i < meetings.size(); ) {
            int time = meetings[i][2] ; 
            vector<int>temp ; 
            while(i<meetings.size() && time == meetings[i][2])
            {
                int u = meetings[i][0];
                int v = meetings[i][1];
               // cout<<u<<" " << v<<endl ; 
                dsu.con(u , v) ; 
                temp.push_back(u) ; 
                temp.push_back(v) ; 
                i++;
            } 

            for(int e : temp)
            {
               // cout<<e<<" " << dsu.find(e) <<endl ; 
                if(dsu.find(e) != dsu.find(0)) 
                {   
                     dsu.pr[e] = e ; 
                }
            }

        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == dsu.find(0)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};