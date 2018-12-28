// the testcase mostly consists of add 

class TwoSum {
public:
    vector<int> nums;
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        unordered_map<int, bool> mp;
        for (int i = 0; i < nums.size(); i ++) {
            if (mp.count(value - nums[i])) return true;
            mp[nums[i]] = true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */