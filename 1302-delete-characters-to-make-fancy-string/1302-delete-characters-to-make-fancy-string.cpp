class Solution {
public:
    string makeFancyString(string s) {
        string ans = "" ; 
        for(int i =0 ; i<s.size() ; i++)
        {
            ans+=s[i] ; 
            while(i+2<s.size() && s[i] == s[i+1] && s[i] == s[i+2])
            {
                i++;
            }
             
        }
        return ans ; 
    }

};