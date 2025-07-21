class Solution {
public:
    int sum = 0;
  
    int sz;
    int arr[10000];
   int arr2[10000] ; 
    Solution(vector<int>& w) {
        sz = w.size();
        for (int i = 0; i < w.size(); i++) {
            sum += w[i];
            arr[i] =sum ;
            arr2[i] = w[i] ;  
           
        }

      
    }

    int pickIndex() {
        int randomNum = max(rand() % sum+1, 1);
        
        for(int i =0 ; i<sz ; i++)
        {
            if(arr[i] > randomNum) return i ;
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */