class LFUCache {
public:
    int size;
    int cap;
    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freq;  /// -> {counter, [[key, value, counter]]->[...]->[...]}
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void updateFrequentyUsed(int key) {
        auto &vec = *(mp[key]);

        int value = vec[1];
        int f     = vec[2];

        freq[f].erase(mp[key]);

        if(freq[f].empty()) {
            freq.erase(f);
        }

        f++;

        freq[f].push_front({key, value, f});

        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        //Get
        auto &vec  = *(mp[key]);

        int value = vec[1];

        //make it frequenty used
        updateFrequentyUsed(key);

        //return
        return value;

    }
    
    void put(int key, int value) {
        if(cap == 0) return;

        if(mp.find(key) != mp.end()) {
            auto &vec  = *(mp[key]);
            vec[1] = value;
            updateFrequentyUsed(key);
        }
        else if(size < cap) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else {
            //Here we remove the Least guy and update accordingly.
            auto &dll = freq.begin()->second;
            int key_to_delete = (dll.back())[0];
            dll.pop_back();

            if(dll.empty()) {
                freq.erase(freq.begin()->first);
            }

            freq[1].push_front(vector<int>({key, value, 1}));

            mp.erase(key_to_delete);
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */