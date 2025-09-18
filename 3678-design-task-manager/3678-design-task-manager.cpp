class TaskManager {
public:
    set<pair<int, int>> st;
    unordered_map<int, int> map;
    unordered_map<int, int> map2;
    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            int a = tasks[i][0];
            int b = tasks[i][1];
            int c = tasks[i][2];
            map[b] = a;
            map2[b] = c;
            st.insert({-c, -b});
        }
    }

    void add(int userId, int taskId, int priority) {
        map[taskId] = userId;
        map2[taskId] = priority;
        st.insert({-priority, -taskId});
    }

    void edit(int taskId, int newPriority) {
        st.erase({-map2[taskId], -taskId});
        map2[taskId] = newPriority;
        st.insert({-newPriority, -taskId});
    }

    void rmv(int taskId) { st.erase({-map2[taskId], -taskId}); }

    int execTop() {
        if (!st.empty()) {
            int u = map[-st.begin()->second];
            st.erase(st.begin());
            return u;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */