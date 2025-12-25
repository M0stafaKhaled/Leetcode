class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long ans =0 ; 
        int re = 0 ; 
        sort(happiness.begin() , happiness.end()) ; 
        int end = happiness.size() -1 ; 
        while(k>0)
        {
            ans+=max(happiness[end --] + re , 0) ; 
            re -- ; 
            k-- ; 
        }
        return ans ; 
    }
};