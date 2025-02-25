class MyHashMap {
public:
    vector<list<pair<int ,int>>> vec;
    int M = 10000;
    int getBucket(int key) {
        return key % M;
    }

    MyHashMap() {
       vec.resize(M);
    }
    
    void put(int key, int value) {
        int bucket = getBucket(key);
        auto &chain = vec[bucket];

        for(auto &it: chain) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }

        chain.emplace_back(key, value);
    }
    
    int get(int key) {
         int bucket = getBucket(key);
        auto &chain = vec[bucket];

        if(chain.empty()) return -1;

        for(auto &it: chain) {
            if(it.first == key) return it.second;
        }

        return -1;
    }
    
    void remove(int key) {
         int bucket = getBucket(key);
        auto &chain = vec[bucket];

        for(auto it = chain.begin(); it != chain.end(); it++) {
            if(it->first == key){
                chain.erase(it);
                return;
            }
        }

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */