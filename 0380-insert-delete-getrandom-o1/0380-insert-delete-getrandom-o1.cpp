class RandomizedSet {
public:
    
    vector<int> v;
    unordered_set<int> vist ; 
    int last = -1;
    unordered_map<int, int> map;
    int sum = 0;
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
        map[v[v.size() -1]] = idx ; 
        map.erase(val);

        int last = v.size() - 1;
        swap(v[idx], v[last]);
        v.pop_back();
        return 1;
    }

    int getRandom() {
        if (!v.size())
            return -1;
        int sz = v.size();
        int randomNum = randomNum = max(rand() % sz, 0);
        int f = 0;
        while (last == randomNum && f < v.size()) {
            randomNum = randomNum = max(rand() % sz, 0);
            f++;
           // vist.erase(v[randomNum]);
        }
        vist.insert(v[randomNum]) ; 
        last = randomNum;
        cout << randomNum << endl;
        return v[randomNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */