class MyHashSet {
private:
    vector<int> hashSet;

public:
    MyHashSet() {
    }
    
    void add(int key) {
        hashSet.push_back(key);
        return;
    }
    
    void remove(int key) {
        for (int i = 0; i < hashSet.size(); ++i) {
            if (hashSet[i] == key) {
                hashSet.erase(hashSet.begin() + i);
                i--;
            }
        }
        return;
    }
    
    bool contains(int key) {
        for (int value : hashSet) {
            if (key == value) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */