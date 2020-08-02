class MyHashSet {
public:
    /** Initialize your data structure here. */
    bitset<1000001> test;
    
    MyHashSet() {
    }
    
    void add(int key) {
        test[key] = 1;
    }
    
    void remove(int key) {
        test[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return test[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */