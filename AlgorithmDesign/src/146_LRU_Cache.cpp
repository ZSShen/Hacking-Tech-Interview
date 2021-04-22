class LRUCache {
public:
    LRUCache(int capacity)
        : capacity(capacity)
    { }

    int get(int key) {

        if (map.count(key) == 0) {
            return -1;
        }

        auto it = map[key];
        int value = it->second;
        nodes.erase(it);

        // Update liveness.
        nodes.push_front({key, value});
        map[key] = nodes.begin();

        return value;
    }

    void put(int key, int value) {

        if (map.count(key) == 1) {
            auto it = map[key];
            nodes.erase(it);
        }

        // Push a new record to the front of the list.
        nodes.push_front({key, value});
        map[key] = nodes.begin();

        // Remove the tail node if the cache is full.
        if (nodes.size() > capacity) {
            int last = nodes.back().first;
            nodes.pop_back();
            map.erase(last);
        }
    }

private:
    int capacity;
    list<pair<int, int>> nodes;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */