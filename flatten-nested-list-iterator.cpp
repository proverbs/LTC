// typical: empty nested array makes it much more complicated.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<vector<NestedInteger>*> arr;
    vector<int> idx;
    NestedIterator(vector<NestedInteger> &nestedList) {
        idx.push_back(-1); // dummy
        if (nestedList.size() == 0) return; // special judge
        arr.push_back(&nestedList);
        int z = 0;
        while (1) {
            if (z != -1 && move_deep(z)) break;
            z = move_shallow();
            if (arr.empty()) break;
        }
        
    }

    int next() {
        int t = idx.back();
        int res = (*arr.back())[t].getInteger();
        
        while (1) {
            if (arr.empty()) break;
            int z = move_shallow();
            if (z != -1 && move_deep(z)) break;
        }
        
        return res;
    }
    
    int move_shallow() {
        int t = idx.back();
        idx.pop_back();
        
        
        if (!arr.empty() && (*arr.back()).size() == t + 1) {
            arr.pop_back();
            return move_shallow();
        }
        
        if (arr.empty()) return -1;
        else return t + 1;
    }
    
    bool move_deep(int t) {
        if (arr.back()->size() != 0 && !(*arr.back())[t].isInteger()) {
            idx.push_back(t);
            arr.push_back(&(*arr.back())[t].getList());
            t = 0;
            return move_deep(t);
        }
        
        if (arr.back()->size() != 0) {
            idx.push_back(t);
            return true;
        } else {
            idx.push_back(-1);
            return false;
        }
    }

    bool hasNext() {
        return !arr.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */