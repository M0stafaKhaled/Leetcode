class Solution {
public:
    
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1 ; 
        int x = 10 ; 
        int prev =9 ; 
    
        for (int i = 2; i <=n; i++) {
            
           int cur =prev ; 
           for(int j =0 ; j<i-1 ; j++)
           {
            cur*=((prev-j));
           }
           x+=cur ; 
            
            
        }
        return x;
    }
};