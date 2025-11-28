class LRUCache {
public:
    priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                   std::greater<std::pair<int, int>>>
        pq;
    int timer = 0;
    int cap = 0;
    int st = 1;
    unordered_map<int, int> map;
    unordered_map<int, int> counter;
    unordered_map<int, int> time_map;
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;

        counter[key]++;
        timer++;
        time_map[timer] = key;
        return map[key];
    }

    void put(int key, int value) {

        map[key] = value;
        counter[key]++;
        timer++;
        // pq.push({timer, key});
        while (map.size() > cap) {
            int k = time_map[st];
            st++;
            counter[k]--;
            if (counter[k] <= 0) {
                map.erase(k);
                counter.erase(k);
            }
        }
        time_map[timer] = key;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */