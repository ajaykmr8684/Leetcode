class LRUCache {
public:
    int n;
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();

    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        makeRecentlyUsed(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else {
            
        dll.push_front(key);
        mp[key] = {dll.begin(), value};
        n--;
        }

        if(n < 0) {
            int key_to_be_deleted = dll.back();
            mp.erase(key_to_be_deleted);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */