// typical: set lower_bound + comparator

class LogSystem {
public:
    typedef pair<long long, int> pr; // <timestamp, val>
    class Compare {
    public:
        bool operator() (const pr &a, const pr &b) {
            return a.first < b.first;
        }
    };
    
    set<pr, Compare> logs;
    
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        long long x = calc_ts(timestamp);
        logs.insert({x, id});
        set<pr, Compare>::iterator it = logs.begin();
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        long long sa = calc_ts(s, gra, '0');
        long long se = calc_ts(e, gra, '9');
        
        set<pr, Compare>::iterator is, ie;
        is = logs.lower_bound({sa, 0});
        ie = logs.upper_bound({se, 0});
        
        vector<int> res;
        while (is != ie) {
            res.push_back(is->second);
            is ++;
        }
        
        return res;
    }
    
    long long calc_ts(string& ts) {
        string t;
        for (int i = 0; i < ts.length(); i ++) 
            if (ts[i] != ':') t.push_back(ts[i]);
        long long z;
        sscanf(t.c_str(), "%lld", &z);
        return z;
    }
    
    long long calc_ts(string& ts, string& g, char c) {
        int m;
        if (g == "Year") m = 4;
        else if (g == "Month") m = 6;
        else if (g == "Day") m = 8;
        else if (g == "Hour") m = 10;
        else if (g == "Minute") m = 12;
        else m = 14;
        string t;
        for (int i = 0; i < ts.length(); i ++) 
            if (ts[i] != ':') {
                if (t.length() >= m) t.push_back(c);
                else t.push_back(ts[i]);
            }
        long long z;
        sscanf(t.c_str(), "%lld", &z);
        return z;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */