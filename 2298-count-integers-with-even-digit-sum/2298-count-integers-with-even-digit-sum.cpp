class Solution {
public:
    bool solve(int num)
    {
        int cur =0 ; 
        while(num)
        {
            cur+=num%10 ; 
            num/=10 ;
        }

        return cur%2 == 0 ; 
    }
    int countEven(int num) {
        int ans =0 ; 
        for(int i=2 ; i <=num ; i++)
        {
            if(solve(i)) ans++;
        }


        return ans ; 
    }
};