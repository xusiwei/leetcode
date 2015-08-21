/*
copyright xu(xusiwei1236@163.com), all right reserved.

LRU Cache
==========

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/

class LRUCache{
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };

    int capacity_;
    list<Node> cache_;
    unordered_map<int, list<Node>::iterator> index_;
    
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = index_.find(key);
        if( it != index_.end() ) { // found key, move it to the front of cache.
            auto pos = it->second;
            int v = pos->value;
            cache_.push_front(*pos);
            cache_.erase(pos);
            it->second = cache_.begin();
            return v;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it = index_.find(key);
        if( it != index_.end() ) { // found key, update it.
            auto pos = it->second;
            pos->value = value; // update.
            cache_.push_front(*pos);
            cache_.erase(pos);
            it->second = cache_.begin();
        }
        else {
            if( cache_.size() == capacity_ ) { // full, remove the oldest.
                index_.erase(cache_.back().key);  // remove from index
                cache_.pop_back(); // remove from cache.
            }
            cache_.push_front(Node(key, value));
            // index_.insert(make_pair(key, cache_.begin()));
            index_[key] = cache_.begin();
        }
    }
};