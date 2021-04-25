#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key, value;
    Node *next, *prev;
};

class LRUCache {
public:
    Node *head, *tail;
    unordered_map<int, Node*> map;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            update(map[key], map[key]->value);
            return map[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            update(map[key], value);
            return;
        }
        if (map.size() == capacity) {
            map.erase(tail->prev->key);
            remove(tail->prev);
        } 
        Node *new_node = new Node{key, value};
        map[key] = new_node;
        insert_front(new_node);
    }
private:
    void update(Node *node, int value) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->value = value;
        insert_front(node);
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void insert_front(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

};

void print(Node *head) {
    while (head) {
        cout << "(" << head->key << " " << head->value << ")";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1); // cache is {1=1}
    obj->put(2, 2); // cache is {1=1, 2=2}
    cout << obj->get(1) << endl;    // return 1
    // print(obj->head);
    obj->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // print(obj->head);
    cout << obj->get(2) << endl;    // returns -1 (not found)
    obj->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << obj->get(1) << endl;    // return -1 (not found)
    cout << obj->get(3) << endl;    // return 3
    cout << obj->get(4) << endl;    // return 4
    return 0;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */