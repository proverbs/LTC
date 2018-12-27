
class MyHashMap {
public:
    typedef pair<int, int> pr;
    vector<pr> hs;
    static const int MOD = 99999;
    /** Initialize your data structure here. */
    MyHashMap() {
        hs.resize(MOD, {-1, -1});
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int x = key % MOD;
        while (hs[x].first != -1 && hs[x].first != key) x = (x + 1) % MOD;
        hs[x] = {key, value};
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int x = key % MOD;
        while (hs[x].first != -1 && hs[x].first != key) x = (x + 1) % MOD;
        return hs[x].second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int x = key % MOD;
        while (hs[x].first != -1 && hs[x].first != key) x = (x + 1) % MOD;
        hs[x] = {-1, -1};
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */