class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, std::set<pair<int, string>>> key_nts_val;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if (!key_nts_val.count(key)) key_nts_val[key] = std::set<pair<int, string>>();
        key_nts_val[key].insert(make_pair(-timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (!key_nts_val.count(key)) return "";
        else {
            std::set<pair<int, string>>::iterator it;
            it = key_nts_val[key].lower_bound(make_pair(-timestamp, ""));
            if (it == key_nts_val[key].end()) return "";
            else return it->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */