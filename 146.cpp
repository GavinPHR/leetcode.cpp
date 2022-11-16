class Node {
public:
    Node(int key, int val) {
        this->key = key;
        this->val = val;
    }

    Node *prev = nullptr;
    Node *next = nullptr;
    int key;
    int val;
};

class LRUCache {
    Node *head;
    Node *tail;
    unordered_map<int, Node*> m;
    int capacity;

    void pop(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *left, Node *right, Node *node) {
        left->next = node;
        node->prev = right->prev;
        right->prev = node;
        node->next = right;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        auto node = it->second;
        // move out
        pop(node);
        // insert at end
        insert(tail->prev, tail, node);

        return (it->second)->val;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            (it->second)->val = value;
            get(key);
            return;
        }
        // evict first
        if (m.size() == capacity) {
            auto evict = head->next;
            pop(evict);
            m.erase(evict->key);
            delete evict;
        }
        auto node = new Node(key, value);
        m[key] = node;
        insert(tail->prev, tail, node);
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */