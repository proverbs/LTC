// doubly linked list in array

class RandomizedCollection {
public:
    vector<int> arr;
    vector<int> prev, next;
    unordered_map<int, int> idx;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        arr.push_back(val);
        int n = arr.size();
        bool fg;
        if (idx.count(val)) {
            int x = idx[val];
            int nx = next[x];
            if (nx != -1) prev[nx] = n - 1;
            next[x] = n - 1;
            
            prev.push_back(x);
            next.push_back(nx);
            fg = false;
        }
        else {
            prev.push_back(-1);
            next.push_back(-1);
            idx[val] = n - 1;
            fg = true;
        }
        return fg;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        
        bool fg;
        if (idx.count(val)) {
            fg = true;
            
            int x = idx[val];
            
            if (prev[x] == -1 && next[x] == -1) idx.erase(idx.find(val));
            else {
                int px = prev[x], nx = next[x];
                idx[val] = px == -1 ? nx : px;
                if (px != -1) next[px] = nx;
                if (nx != -1) prev[nx] = px;
            }
            
            // move the last value to current position
            int n = arr.size();
            if (x != n - 1) {
                arr[x] = arr[n - 1];
                int y = prev[n - 1];
                prev[x] = y;
                if (y != -1) next[y] = x;
                int z = next[n - 1];
                next[x] = z;
                if (z != -1) prev[z] = x;
                idx[arr[x]] = x;
            }
            arr.pop_back();
            prev.pop_back();
            next.pop_back();
        } else fg = false;
        return fg;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */