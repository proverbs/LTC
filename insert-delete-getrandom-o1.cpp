// classic: to implement O(1) random, we can only use array.
// and to implement O(1) insert/remove, we can only use hashmap. 

class RandomizedSet {
public:
    vector<int> num;
    unordered_map<int, int> num2ind;
    /** Initialize your data structure here. */
    RandomizedSet() {
        num2ind.clear();
        num.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (num2ind.count(val)) return false;
        else {
            num.push_back(val);
            num2ind[val] = num.size() - 1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!num2ind.count(val)) return false;
        else {
            int idx = num2ind[val];
            num[idx] = num[num.size() - 1];
            num2ind[num[idx]] = idx;
            num.pop_back();
            num2ind.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return num[rand() % num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */