class LRUCache {
public:
    // cache = map (since storing key, value pairs)
    map<int,int> cache;
    map<int,list<int>::iterator> address;
    list<int> dll;
    int cap;
    int siz;
    
    LRUCache(int capacity) {
        this->cap = capacity;
        this->siz = 0;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())return -1;
        
        dll.erase(address[key]);
        dll.push_front(key);
        address.erase(key);
        address[key] = dll.begin();
        
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            dll.erase(address[key]);
            address.erase(key);
            cache.erase(key);
            siz--;
        }
        
        if(siz==cap){
            int toDel = dll.back();
            dll.pop_back();
            address.erase(toDel);
            cache.erase(toDel);
            siz--;
        }
        
        cache[key] = value;
        dll.push_front(key);
        address[key] = dll.begin();
        siz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */