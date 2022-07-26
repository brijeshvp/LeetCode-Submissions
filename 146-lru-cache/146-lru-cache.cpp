class LRUCache {
public:
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
        if(!cache.count(key))return -1;
        
        dll.erase(address[key]);
        dll.push_front(key);
        address[key] = dll.begin();
        
        return cache[key];
    }
    
    void put(int key, int value) {
        if(siz==cap){
            if(cache.count(key)){
                dll.erase(address[key]);
                dll.push_front(key);
                address[key] = dll.begin();
                cache[key] = value;
            } 
            else{
                int toDel = dll.back();
                cache.erase(toDel);
                dll.erase(address[toDel]);
                address.erase(toDel);
                
                dll.push_front(key);
                address[key] = dll.begin();
                cache[key] = value;
            }
        }
        else{
            if(cache.count(key)){
                dll.erase(address[key]);
                dll.push_front(key);
                address[key] = dll.begin();
                cache[key] = value;
            }
            else{
                siz++;
                cache[key] = value;
                dll.push_front(key);
                address[key] = dll.begin();
            }
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */