class AllOne {
public:
    struct Bucket {
        Bucket* prev;
        Bucket* next;
        unordered_set<string> st;
        long long  freq;
        Bucket(long long v) { freq = v; }
    };
    unordered_map<string, Bucket*> keyToBucket;
    Bucket* head;
    Bucket* tail;
    void insertAfter(Bucket* node, Bucket* newBucket) {
        newBucket->next = node->next;
        newBucket->prev = node;
        node->next->prev = newBucket;
        node->next = newBucket;
    }
    void insertBefore(Bucket* node, Bucket* newBucket) {
        newBucket->next = node;
        newBucket->prev = node->prev;
        node->prev->next = newBucket;
        node->prev = newBucket;
    }
    void removeBucket(Bucket* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    AllOne() {

        head = new Bucket(0);
        tail = new Bucket(10000000);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (keyToBucket.find(key) == keyToBucket.end()) {
            if (head->next->freq == 1) {
                head->next->st.insert(key);
                keyToBucket[key] = head->next;

            } else {
                Bucket* newbucket = new Bucket(1);
                insertAfter(head, newbucket);
                newbucket->st.insert(key);
                keyToBucket[key] = newbucket;
            }
            return;
        }

        Bucket* cur = keyToBucket[key];
        long long  cur_freq = cur->freq;
        cur->st.erase(key);
        if (cur->next->freq == cur_freq + 1) {
            Bucket* next = cur->next;
            next->st.insert(key);
            keyToBucket[key] = next;
        } else {
            Bucket* next = new Bucket(cur_freq + 1);
            insertAfter(cur, next);
            next->st.insert(key);
            keyToBucket[key] = next;
        }

        if (cur->st.empty()) {
            removeBucket(cur);
        }
    }

    void dec(string key) {
        if (keyToBucket.find(key) == keyToBucket.end())
            return;

        Bucket* cur = keyToBucket[key];
        int cur_freq = cur->freq;

        if (cur_freq == 1) {
            keyToBucket.erase(key);
            cur->st.erase(key);

            if (cur->st.empty()) {
                removeBucket(cur);
            }
            return;
        }

        cur->st.erase(key);
        if (cur->prev->freq == cur_freq - 1) {
            Bucket* prev = cur->prev;
            prev->st.insert(key);
            keyToBucket[key] = prev;
        } else {
            Bucket* prev = new Bucket(cur_freq - 1);
            insertBefore(cur, prev);
            prev->st.insert(key);
            keyToBucket[key] = prev;
        }

        if (cur->st.empty()) {
            removeBucket(cur);
        }
    }

    string getMaxKey() {
        Bucket* cur = tail->prev;
        if (cur == head || cur == tail)
            return "";
        auto ans = cur->st.begin();
        if (cur->st.empty())
            return "";
        return *ans;
    }

    string getMinKey() {

        Bucket* cur = head->next;
       if (cur == head || cur == tail)
            return "";

        auto ans = cur->st.begin();
        if (cur->st.empty())
            return "";
        return *ans;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */