class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans =0 ; 
        int cur =0 ; 
        int start =0 ; 
        unordered_set<char> set ; 
        for(int i =0 ; i<s.size() ;i++)
        {
            if(set.find(s[i]) == set.end())
            {
                cur++ ;
                set.insert(s[i]);
            }
            else
            {
              ans = max(cur , ans);
              cur++;
              while(set.find(s[i]) != set.end())
              {
                 set.erase(s[start]);
                 start++;
                 cur--;
              }
               set.insert(s[i]);

                ans = max(cur , ans);
              
                //  set.insert(s[i]);
            }
        }

        return max(cur , ans) ; 
    }
};