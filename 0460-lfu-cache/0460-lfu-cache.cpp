struct Node {
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
    Node(int k, int v)
        : key(k), val(v), prev(nullptr), next(nullptr), freq(1) {}
};

class List {
public:
    Node* head;
    Node* tail;
    int size;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast() {
        if (size == 0)
            return nullptr;
        Node* last = tail->prev;
        removeNode(last);
        return last;
    }
};

class LFUCache {
public:
    int cap;

    int minFreq;

    unordered_map<int, Node*> keyToNode;

    unordered_map<int, List*> freqToList;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end())
            return -1;
        int number_of_cur_freq = 0;
        Node* node = keyToNode[key];
        int cur_freq = node->freq;
        freqToList[cur_freq]->removeNode(node);
        number_of_cur_freq = freqToList[cur_freq]->size;

        if (freqToList.find(cur_freq + 1) == freqToList.end()) {
            freqToList[cur_freq + 1] = new List();
        }
        freqToList[cur_freq + 1]->addToFront(node);
        node->freq++;
        if (minFreq == cur_freq && number_of_cur_freq == 0) {
            minFreq++;
        }

        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyToNode.find(key) != keyToNode.end()) {
            keyToNode[key]->val = value;
            get(key);
            return;
        }
        if (cap == keyToNode.size()) {
            Node* node = freqToList[minFreq]->removeLast();
            keyToNode.erase(node->key);
        }

        int cur_freq = 1;
        if (freqToList.find(cur_freq) == freqToList.end()) {
            freqToList[cur_freq] = new List();
        }
        Node* node = new Node(key, value);
        freqToList[cur_freq]->addToFront(node);
        keyToNode[key] = node;
        minFreq = cur_freq;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */