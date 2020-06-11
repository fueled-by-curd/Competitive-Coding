class LRUCache {
public:
    int sz;
    unordered_map<int, list<pair<int, int>>::iterator> dict; 
    list<pair<int, int>> cache;
    
    LRUCache(int capacity) 
    {
        sz = capacity;
    }
    
    int get(int key) 
    {
        if( dict.find(key) == dict.end())
            return -1;
        
        auto it = dict[key];
        int val = it->second;
        cache.erase(it);
        cache.push_front(make_pair(key,val));
        dict[key] = cache.begin();
        return val;
    }
    void put(int key, int value) 
    {
        if(dict.find(key) != dict.end()) 
        {
            auto it = dict[key];
            cache.erase(it);
        }
        else 
        {
            if(cache.size() == sz) 
            {
                pair<int, int> lru = cache.back();
                cache.pop_back();
                dict.erase(lru.first);
            }
        }

        cache.push_front(make_pair(key,value));
        dict[key] = cache.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
