class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>q ; 
        vector<int> ans;
        for(int i =0 ; i<nums.size() ; i++)
        {
            while(q.size() && nums[i] > q.back())
            {
                q.pop_back();
            }
            q.push_back(nums[i]) ; 

            if(i>=k-1)
            {
                ans.push_back(q.front()) ;
                int f = (i-k)+1 ; 
               if(q.size() && q.front() == nums[f])
               {
                q.pop_front() ; 
               }
            }
            
        }

        return ans ; 
    }
};