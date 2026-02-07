class Solution {
public:
    int minimumDeletions(string s) {
            int ans =s.size() ; 
          int a_count =0 ; 
            if(s.size() ==1) return 0;
             
        for(int i =s.size()-1 ; i>=0;i--)
        {
          
           if(s[i] == 'a') a_count++;
        }
        int b_count =0 ; 
        for(int i =0 ; i<s.size() ; i++)
        {
            if(s[i] == 'a')a_count--;
            ans = min (ans, b_count+ a_count);
            if(s[i] == 'b') b_count ++;
             
        }

        return ans; 
    }
};