class Solution {
public:
    int minJumps(vector<int>& arr) {

        vector<int> de(arr.size(), 1e9);
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]].push_back(i);
        }
        de[0] = 0;
        queue<int> q;
        q.push(0);

        while (q.size()) {
            int top = q.front();
            q.pop();
            int v = arr[top];
            for (int i = map[v].size() - 1; i >= 0; i--) {
                int cur = map[v][i];

                if (de[cur] > de[top] + 1) {
                    de[cur] = de[top] + 1;
                    q.push(cur);
                }
                map[v].pop_back();
            }
            if (top - 1 >= 0 && de[top - 1] > de[top] + 1) {
                de[top - 1] = de[top] + 1;
                q.push(top - 1);
            }

            if (top + 1 < arr.size() && de[top + 1] > de[top] + 1) {
                de[top + 1] = de[top] + 1;
                q.push(top + 1);
            }
        }

        return de.back();
    }
};