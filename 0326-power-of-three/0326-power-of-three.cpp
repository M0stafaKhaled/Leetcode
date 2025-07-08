class Solution {
public:
    bool solve(int n , long long num)
    {
        if(num >n) return  false;
        if(n == num) return true ; 

        return solve(n , num*3);
    }
    bool isPowerOfThree(int n) {

     return solve(n , 1) ;    
    }
};