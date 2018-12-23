// typical: O(1) get -> hashtable, O(1) modification(+1/-1) to maintain order -> linked list

class LFUCache {
public:
    struct Node {
        int k, v, f;
        Node(int k, int v, int f) : k(k), v(v), f(f) {}
    };
    list<list<Node>> fl;
    unordered_map<int, list<list<Node>>::iterator> fmap;
    unordered_map<int, list<Node>::iterator> kmap;
    int cap;
    int sz;
    LFUCache(int capacity) {
        fl.clear();
        fmap.clear();
        kmap.clear();
        cap = capacity;
        sz = 0;
    }
    
    int get(int key) {
        if (!kmap.count(key)) return -1;
        modify(key);
        return kmap[key]->v;
    }
    
    void put(int key, int value) {
        if (!cap) return;
        if (kmap.count(key)) {
            kmap[key]->v = value;
            modify(key);
        } else {
            // evict
            if (sz == cap) evict();
            
            // insert
            insert(key, value);
            sz ++;
        }
    }
    
    void modify(int key) {
        list<Node>::iterator p = kmap[key];
        Node sp = *p;
        list<list<Node>>::iterator rw = fmap[p->f];
        list<list<Node>>::iterator nt = rw;
        nt ++;
        
        // remove from fmap, remove from list
        if (rw->size() == 1) {
            fmap.erase(fmap.find(sp.f));
            fl.erase(rw);
        }
        else rw->erase(p);
        
        // insert to list
        sp.f += 1;
        rw = nt;
        if (fmap.count(sp.f)) {
            fmap[sp.f]->push_back(sp);
        } else {
            fl.insert(rw, list<Node>());
            rw --;
            rw->push_back(sp);
            // modify fmap
            fmap[sp.f] = rw;
        } 
        
        
        // modify kmap
        kmap[key] = rw->end();
        kmap[key] --;
    }
    
    void evict() {
        Node z = fl.front().front();
        
        // remove from fmap
        if (fl.front().size() == 1) fmap.erase(fmap.find(z.f));
        sz --;
        
        // remove from kmap
        kmap.erase(kmap.find(z.k));
        
        
        // remove from list
        fl.front().pop_front();
        if (fl.front().empty()) fl.pop_front();
        
    }
    
    void insert(int key, int val) {
        // list insert
        fl.push_front(list<Node>());
        fl.front().push_front(Node(key, val, 0));
        
        // fmap insert
        fmap[0] = fl.begin();
        
        // kmap insert
        kmap[key] = fl.front().begin();
        
        modify(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */