class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*>
        map;

    Node* head;
    Node* tail;
    int cap;
    void removeNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;
        Node* node = map[key];
        moveToFront(node);
        return node->val;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void put(int key, int value) {

        if (map.find(key) == map.end()) {
            if (map.size() == cap) {
                Node* node = tail->prev;

                map.erase(node->key);
                removeNode(node);
            }
            Node* cur = new Node(key, value);
            addToFront(cur);
            map[key] = cur;
        } else {
             moveToFront(map[key]);
            map[key]->val = value;
           
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */