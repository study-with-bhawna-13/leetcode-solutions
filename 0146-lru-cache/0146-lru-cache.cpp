struct DLL {
    int key, value;
    DLL *next, *prev;
};
class LRUCache {
    unordered_map<int, DLL*> m;
    DLL *head, *tail;
    int capacity;
    // insert at head
    // delete from tail
    void addNode(DLL *node){
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
    void deleteNode(DLL *node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

public:
    LRUCache(int capacity) {
        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            DLL* node = m[key];
            deleteNode(node);
            addNode(node);
            return node->value;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            DLL *node = m[key];
            deleteNode(node);
            addNode(node);
            node->value = value;
        } else {
            if (m.size() == capacity) {
                DLL* tmp = tail->prev;
                deleteNode(tmp);
                m.erase(tmp->key);
                delete tmp;
            }
            DLL* node = new DLL(key, value);
            addNode(node);
            m[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */