class MyCalendar {
public:
    map<int, int> cal;
    MyCalendar() {
        cal.clear();
        cal[-2] = -1;
        cal[1e9 + 1] = 1e9 + 2;
    }
    
    bool book(int start, int end) {
        // there are all 4 ways to lead to a overlap
        // an important difference from segment overlap: NO overlap during the runtime
        // so start time can determine the interval order
        auto p = cal.lower_bound(start + 1);
        if (p->first < end) return false;
        p --;
        if (p->second > start) return false;
        cal[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */