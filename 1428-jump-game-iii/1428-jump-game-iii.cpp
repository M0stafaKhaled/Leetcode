class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        queue<int> q;
        q.push(start);
        vector<int> vist(arr.size());
        vist[start] = 1;
        while (q.size()) {
            int top = q.front();
            q.pop();
            if (arr[top] == 0)
                return 1;

            int a = arr[top] + top;
            int b = top - arr[top];
            if (a >= 0 && a < arr.size() && !vist[a]) {
                vist[a] = 1;
                q.push(a);
            }

            if (b >= 0 && b < arr.size() && !vist[b]) {
                vist[b] = 1;
                q.push(b);
            }
        }

        return 0;
    }
};