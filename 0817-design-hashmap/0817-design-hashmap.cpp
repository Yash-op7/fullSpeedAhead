class MyHashMap {
    unordered_map<int, int> dict;
public:
    MyHashMap() {
        dict.clear();
    }
    
    void put(int key, int value) {
        dict[key] = value;
    }
    
    int get(int key) {
        if(dict.find(key) == dict.end()){
            return -1;
        }
        return dict[key];
    }
    
    void remove(int key) {
        if(dict.find(key) == dict.end()){
            return;
        }
        dict.erase(dict.find(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */