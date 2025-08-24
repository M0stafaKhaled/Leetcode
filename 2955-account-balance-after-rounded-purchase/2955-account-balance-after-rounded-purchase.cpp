class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        int l =  p%10 ; 
        if(l>=5) 
        {
            p/=10 ;
            p*=10; 
            p+=10 ; 
        } 
        else
        {
            p/=10 ; 
            p*=10 ; 

        }
        return 100 -p ; 
    }
};