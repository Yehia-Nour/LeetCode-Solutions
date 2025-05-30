class DLL {
public:
    int key, val;
    DLL* prev;
    DLL* next;

    DLL(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, DLL*> map;
    DLL* head; 
    DLL* tail; 

    void remove(DLL* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(DLL* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new DLL(0, 0);
        tail = new DLL(0, 0); 
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.count(key)) {
            DLL* node = map[key];
            remove(node);
            insert(node); 
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            DLL* node = map[key];
            node->val = value;
            remove(node);
            insert(node);
        } else {
            if (map.size() == capacity) {
                DLL* lru = tail->prev;
                map.erase(lru->key);
                remove(lru);
                delete lru;
            }

            DLL* newNode = new DLL(key, value);
            insert(newNode);
            map[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */