class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> maps ; 

        for(int i =0 ;i<nums.size() ;i++)
        {
         
            int x = target - nums[i] ; 
            if(maps.find(x) != maps.end() )
                {
                    return { i , maps[x]};
                }
            maps[nums[i]] = i ; 
        }
       

        return {-1 , -1};
    }
};