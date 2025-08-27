class Solution {
public:
    int reverse(int x) {
        bool sing = true ; 
        if(x==-1<<31) return 0 ; 
        if(x <0) 
        {
            sing = 0 ; 
            x= x*-1 ; 
        }
        while(x&&x%10 ==0)
        {
            x/=10 ; 
        }
        long long  ans =0 ; 
        while(x)
        {
            ans+=x%10 ; 
            x/=10 ; 
            if(x)
            ans*=10 ; 
          
        }
        if(!sing) ans*=-1 ; 
        if(ans > (1L<<31) || ans < -1<<31) return 0 ; 
        return ans ; 
    }
};