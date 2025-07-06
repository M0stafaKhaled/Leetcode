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

    int get_root(vector<int>& leftChild, vector<int>& rightChild) {

        unordered_set<int> st ; 
        int n = leftChild.size();

        for(int i =0 ; i<leftChild.size() ; i++)
        {
            int left = leftChild[i] ; 
            int right = rightChild[i] ; 
            if(~left)   st.insert(left) ; 
            if(~right)  st.insert(right) ; 
        } 
        int ans = -1 ; 

        for(int i =0 ; i<n;i++)
        {
            if(st.find(i) == st.end()) return i;
        }
        return -1 ; 
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {

        DSU dsu(n+1);
        int root = get_root(leftChild ,rightChild );
        if(root ==-1) return 0;
        queue<int> q; 
        q.push(root) ;
        dsu.con(n , root) ; 
        while(q.size())
        {

            int top = q.front() ; 
            q.pop() ; 
           
            vector<int> chs ; 
          
            chs.push_back(leftChild[top]) ;
             chs.push_back(rightChild[top]) ;  

             for(int e : chs)
             {
                if(e== -1) continue ; 
                if(dsu.find(e) != e) return false ; 
                dsu.con(n , e);
                q.push(e);
             }



        }

        for (int i = 0; i < n; i++) {
            if (dsu.find(i) !=  n)
                return 0;
        }
        return 1;
    }
};