class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        int ans =-1 ; 
        unordered_map<int ,int> map ;
        for(int i =0 ; i<arr.size() ; i++)
        {
            map[arr[i]]++;
           
        }
        for(auto e : map)
        {
             if(e.first == e.second)
            {
                ans  = max(ans , e.first);
            }
        }
        return ans ; 
    }
};