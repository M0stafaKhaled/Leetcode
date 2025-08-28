class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans =0 ; 
        unordered_map<int , int> map ; 
        for(int i =0  ; i<answers.size() ; i++)
        {
            map[answers[i]] ++; 
        }

        for(auto e : map)
        {
            int a = e.first ; 
            int b = e.second ; 
            if(a >= b) ans+=a+1;
            else 
            {
                int f =b+1 ;
                int temp = b ;  
                while(temp>0)
                {
                   temp-=(a+1); 
                   if(temp<=0) ans+=a+1 ;
                   else 
                   ans+= a+1;
                }
            } 
        }
        return ans ; 
    }
};