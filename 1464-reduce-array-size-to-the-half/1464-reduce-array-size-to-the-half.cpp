class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int , int> map ; 
        for(int i =0 ; i<arr.size() ; i++)
        {
            map[arr[i]] ++; 
        }
        int n = arr.size() ; 
        priority_queue<int> pq ; 
        for(auto e : map)
        {
            pq.push(e.second) ; 
        }
        int ans =0 ; 
        while(pq.size() && n > arr.size()/2)
        {
            int top = pq.top() ;
            pq.pop() ; 
            n-=top ; 
            ans++;
        }
        return ans ; 
    }
};