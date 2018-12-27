
// inc/dec by 1 --> linked list
// O(1)

class AllOne {
public:
    typedef pair<string, int> pr;
    list<list<pr>> lt;
    unordered_map<string, list<pr>::iterator> kmap;
    unordered_map<int, list<list<pr>>::iterator> vmap;
    
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!kmap.count(key)) {
            // add new
            if (!vmap.count(1)) {
                lt.insert(lt.begin(), list<pr>());
                vmap[1] = lt.begin();
            }
            vmap[1]->insert(vmap[1]->begin(), {key, 1});
            kmap[key] = vmap[1]->begin();
            
        } else {
            int val = kmap[key]->second;
            list<list<pr>>::iterator it = vmap[val], itx = vmap[val];
            itx ++;
            if (itx == lt.end() || itx->begin()->second != val + 1) {
                lt.insert(itx, list<pr>());
                itx --;
            }

            // remove
            it->erase(kmap[key]);
            if (it->empty()) vmap.erase(vmap.find(val)), lt.erase(it);

            // add new
            vmap[val + 1] = itx;
            itx->insert(itx->begin(), {key, val + 1});
            kmap[key] = itx->begin();
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!kmap.count(key)) return;
        int val = kmap[key]->second;
        list<list<pr>>::iterator it = vmap[val];
        if (val == 1) {
            // remove
            it->erase(kmap[key]);
            kmap.erase(kmap.find(key));
            if (it->empty()) vmap.erase(vmap.find(val)), lt.erase(it);
        } else {
            list<list<pr>>::iterator itx = it;
            if (itx == lt.begin()) {
                lt.insert(itx, list<pr>());
                itx --;
            } else {
                if (!vmap.count(val - 1)) lt.insert(itx, list<pr>());
                itx --;
            }
            
            // remove
            it->erase(kmap[key]);
            if (it->empty()) vmap.erase(vmap.find(val)), lt.erase(it);
            
            //add new
            vmap[val - 1] = itx;
            itx->insert(itx->begin(), {key, val - 1});
            kmap[key] = itx->begin();
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (lt.empty()) return "";
        list<list<pr>>::iterator it = lt.end();
        it --;
        return it->begin()->first;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (lt.empty()) return "";
        return lt.begin()->begin()->first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */