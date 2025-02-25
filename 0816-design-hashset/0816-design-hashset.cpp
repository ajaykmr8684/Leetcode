class MyHashSet {
public:
    int M;
    vector<list<int>> vec;
    int getIndex(int key) {
        return key % M;
    }
    MyHashSet() {
        M = 15000;
        vec = vector<list<int>>(M, list<int> {});
    }
    
    void add(int key) {
        int index = getIndex(key);
        auto itr = find(vec[index].begin(), vec[index].end(), key);
        if(itr == vec[index].end())
            vec[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto itr = find(vec[index].begin(), vec[index].end(), key);

        if(itr != vec[index].end()){
            vec[index].remove(key);
        }
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        auto itr = find(vec[index].begin(), vec[index].end(), key);

        return itr != vec[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */