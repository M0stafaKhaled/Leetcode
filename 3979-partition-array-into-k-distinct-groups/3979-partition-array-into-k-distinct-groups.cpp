class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int x : nums) freq[x]++;

        // Max heap by frequency
        priority_queue<pair<int,int>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }

        // Process
        while (!pq.empty()) {
            int used = 0;
            vector<pair<int,int>> temp; // store decremented elements for re-push

            // Take up to k distinct elements
            while (!pq.empty() && used < k) {
                auto [cnt, val] = pq.top();
                pq.pop();
                used++;

                if (cnt > 1) {
                    temp.push_back({cnt - 1, val});
                }
            }

           
            if (used < k) return false;

        
            for (auto &p : temp) pq.push(p);
        }

        return true;
    }
};
