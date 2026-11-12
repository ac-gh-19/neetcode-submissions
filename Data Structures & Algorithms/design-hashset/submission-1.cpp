class MyHashSet {
private:
    bool arr[10000001] = {false};
public:
    MyHashSet() {
    }
    
    void add(int key) {
        if (arr[key]) return;
        arr[key] = true;
    }
    
    void remove(int key) {
        if (arr[key]) arr[key] = false;
        return;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */