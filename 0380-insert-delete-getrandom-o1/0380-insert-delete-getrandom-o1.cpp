class RandomizedSet {
public:

    vector<int> v;
   int last = -1;
    unordered_map<int, int> map;
   
    RandomizedSet() {}

    bool insert(int val) {
        bool ans = map.find(val) != map.end();
        if (!ans) {
            v.push_back(val);
            map[val] = v.size() - 1;
        }

        return !ans;
    }

    bool remove(int val) {
        bool ans = map.find(val) != map.end();
        if (!ans)
            return 0;
        int idx = map[val];
        int last = v.size() - 1;
        map[v[last]] = idx ; 
        map.erase(val);        
        swap(v[idx], v[last]);
        v.pop_back();
        return 1;
    }

    int getRandom() {
      return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */