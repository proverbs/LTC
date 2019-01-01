// O(logn) for seat and leave
int gn;
class ExamRoom {
public:
    typedef pair<int, int> pr;
    
    class Compare {
    public:
        bool operator() (const pr &a, const pr &b) {
            // be careful to the range when its left is 0, or its right is (n-1)
            int av = a.second - 1 >> 1, bv = b.second - 1 >> 1;
            if (a.first == 0 || a.first + a.second == gn) av = a.second - 1;
            if (b.first == 0 || b.first + b.second == gn) bv = b.second - 1;
            if (av == bv) return a.first < b.first;
            return av > bv;
        }
    };
    
    set<pr, Compare> st;
    unordered_map<int, set<pr>::iterator> prev, next;
    int n;
    
    ExamRoom(int N) {
        n = N;
        st.insert({0, N});
        gn = n;
    }
    
    int seat() {
        auto it = st.begin();
        int lt = it->first;
        int rt = it->second + lt - 1;
        st.erase(it); // must delete first, because operator== is not used by std::set. Elements a and b are considered equal iff !(a < b) && !(b < a)
        int mid;
        
        if (lt == 0) mid = 0;
        else if (rt == n - 1) mid = n - 1;
        else mid = lt + rt >> 1;
        
        if (mid - lt > 0) {
            auto lit = st.insert({lt, mid - lt});
            prev[mid] = lit.first;
            lt --;
            if (lt >= 0) next[lt] = lit.first;
            
        } else {
            lt --;
            if (lt >= 0) next.erase(next.find(lt));
        }
        
        if (rt - mid > 0) {
            auto rit = st.insert({mid + 1, rt - mid});
            next[mid] = rit.first;
            rt ++;
            if (rt < n) prev[rt] = rit.first;
        } else {
            rt ++;
            if (rt < n) prev.erase(prev.find(rt));
        }
        
        return mid;
    }
    
    void leave(int p) {
        int llt, rrt;
        if (prev.count(p)) {
            auto lit = prev[p];
            prev.erase(prev.find(p));
            llt = lit->first;
            st.erase(lit);
        } else {
           llt = p; 
        }
        
        if (next.count(p)) {
            auto rit = next[p];
            next.erase(next.find(p));
            rrt = rit->first + rit->second - 1;
            st.erase(rit);
        } else {
            rrt = p;
        }
        auto cur = st.insert({llt, rrt - llt + 1});
        
        llt --;
        rrt ++;
        if (llt >= 0) next[llt] = cur.first;
        if (rrt < n) prev[rrt] = cur.first;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */