class Solution {
public:
   
    int kthGrammar(int n, int k) {

       if(n==1) return 0 ;
       int mid = 1<<(n-2) ; 
       if(k<=mid)
       {
        return kthGrammar(n-1 , k);
       }else
        return 1-kthGrammar(n-1 , k-mid);
    }
};