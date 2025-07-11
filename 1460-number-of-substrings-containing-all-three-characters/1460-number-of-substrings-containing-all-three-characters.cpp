class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]  ;
        int start =0 ; 
        int ans =0 ; 
        for(int i =0 ; i<s.size() ; i++)
        {
            arr[s[i] -'a']++;

            while(i>=start &&arr[0] >=1 && arr[1] >=1 && arr[2] >=1)
            {
                arr[s[start] -'a'] -- ; 
                start++;
            }
            ans+=start ; 
           
        }

        return ans ; 
    }
};