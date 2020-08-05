typedef pair<int,int> pii;

class LRUCache {
private:
    
    list<pii> data;
    int n;
    map<int,list<pii>::iterator> hsh;
    
    void movetop(map<int,list<pii>::iterator>::iterator &it,int value = -1){
        // Get The value
        pii x = *(it->second);
        // Erase it from list
        data.erase(it->second);
        if(value != -1){
            x.second = value;
        }
        // push the value to front
        data.push_front(x);
        // update the hash
        hsh[x.first] = data.begin();
    }
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        // if exist move to top
        auto it = hsh.find(key);
        if(it == hsh.end()) return -1;
        int ans = (it->second)->second;
        // move to top
        movetop(it);
        return ans;
    }
    
    void put(int key, int value) {
        auto it = hsh.find(key);
        if(it != hsh.end()){
            movetop(it,value);
            // Update Value
        }else{
            if(data.size() == n){
                // Remove the least used
                int key = data.back().first;
                cout<<data.back().first<<endl;
                hsh.erase(hsh.find(key));
                data.pop_back();                
            }
            data.push_front({key,value});
            hsh[key] = data.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */