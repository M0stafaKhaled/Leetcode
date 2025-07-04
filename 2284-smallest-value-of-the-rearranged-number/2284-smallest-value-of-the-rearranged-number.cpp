class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int>arr ; 
        if(num ==0) return num ; 
        while(num)
        {
            arr.push_back(num%10) ; 
            num/=10 ; 

        }

        sort(arr.begin() , arr.end()) ; 
        int start =0 ; 
        while(arr[start] ==0) start ++;
        if(start == arr.size()) return 0 ; 

        long long  first = arr[start];
        first*=pow(10 , start) ; 
        for(int i =start+1 ; i<arr.size() ; i++)
        {
            first*=10 ; 
            first+=arr[i] ; 
        }


        return first ; 
    }
};