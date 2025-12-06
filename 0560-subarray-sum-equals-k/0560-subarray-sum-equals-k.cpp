class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // 1,2,-3,4  k=3
        // 2

        // 1,1,1,1 k=2
        // 3

        // 1,2,3 k=3
        // 2

        // 4 , 1 , -1 , 3 , 0,2 ,3 k=3
        //4 , 5 , 4 ,  7 ,  7,9,12
        // 5
        //check(sum -k) ans+=1;

        unordered_map<int , int> map ; 
        map[0] =1 ; 
        int sum =0 ; 
        int ans =0 ; 
        for(int i =0 ; i<nums.size() ; i++)
        {

                sum+=nums[i] ; 

                if(map.find(sum -k) != map.end())
                {
                    ans+=map[sum-k] ; 
                }
                map[sum]++; 
        }

        return ans ; 
       
    }
};