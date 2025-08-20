class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k == points.size())
            return points;
    priority_queue<pair<double , int>, vector<pair<double , int>>, greater<pair<double , int>>> pq;

    for(int i =0 ; i<points.size() ; i++)
    {
        int a = (points[i][0] -0) * (points[i][0] -0) ;
        int b =  (points[i][1] -0) * (points[i][1] -0) ;
        double  f = sqrt(a+b) ; 
        pq.push({f , i}) ;
    }
    vector<vector<int>> ans ; 
    while(pq.size() && k--)
    {
        auto[x ,y] = pq.top() ; 
        pq.pop() ; 
        ans.push_back({points[y][0] ,points[y][1]}) ; 
    }
        return ans;
    }
};