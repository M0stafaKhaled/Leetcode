#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T>
using ordered_set = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

class Router {
public:
    int limit = 0;
    unordered_map<int, ordered_set<pair<int,int>>> mp; // destination -> {(timestamp, source)}
    queue<array<int, 3>> q;

    Router(int memoryLimit) { limit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        if (mp[destination].find({timestamp, source}) != mp[destination].end())
            return false;

        if ((int)q.size() >= limit) {
            auto cur = q.front(); q.pop();
            mp[cur[1]].erase({cur[2], cur[0]});
        }
        mp[destination].insert({timestamp, source});
        q.push({source, destination, timestamp});
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto cur = q.front(); q.pop();
        mp[cur[1]].erase({cur[2], cur[0]});
        return {cur[0], cur[1], cur[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &s = mp[destination];
        if (s.empty()) return 0;
        int left  = s.order_of_key({startTime, INT_MIN});
        int right = s.order_of_key({endTime+1, INT_MIN});
        return right - left; 
    }
};
