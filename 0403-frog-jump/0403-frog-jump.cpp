class Solution {
public:
    vector<vector<long long>> db ; 
    bool solve(vector<int> & stones, int idx, int k) {
     //   cout<<"idx " <<  idx << " "  << k <<endl ;  
        if (idx + 1 == stones.size())
            return true;
        int cur = stones[idx];
        bool ans = false;
        if(db[idx][k] != -1) return db[idx][k] ; 
        for (int i = idx + 1; i < stones.size(); i++) {
            int next = stones[i];
          
        
            if (cur + (k) == next) {
                ans = ans || solve(stones, i, k);
            } 
            
             if (cur + (k + 1) == next) {
                ans = ans || solve(stones, i, k + 1);
            }

             if (cur + (k - 1) == next) {
                ans = ans || solve(stones, i, k - 1);
            }
            if(ans) 
            {
                db[idx][k] = true  ;
                return 1 ;   
            }

           
        }
         return  db[idx][k] =  ans;
    }

        bool canCross(vector<int> & stones) {
            
           // long long  md = stones[stones.size() -1];
            db = vector<vector<long long >>(stones.size() , vector<long long >(3000 , -1)) ;  
           return solve(stones , 0 , 0) ; 
        }
    };