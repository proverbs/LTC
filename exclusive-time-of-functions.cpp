class Solution {
public:
    vector<int> res;
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        res.resize(n, 0);
        dfs(logs, 0, logs.size() - 1);
        return res;
    }
    
    int dfs(vector<string>& logs, int lt, int rt) {
        if (rt < lt) return 0;
        int k = 0, a = lt;
        int pid, t, spid;
        string s;
        int stt, edt;
        int sumt;
        int rg;
        
        interpret(logs[lt], spid, s, stt);
        interpret(logs[rt], spid, s, edt);
        rg = edt - stt + 1;
        sumt = 0;
        
        for (int i = lt; i <= rt; i ++) {
            if (k == 0) lt = i;
            interpret(logs[i], pid, s, t);
            if (s[0] == 's') k ++;
            else {
                k --;
                if (!k) {
                    int st = dfs(logs, lt + 1, i - 1);
                    interpret(logs[lt], pid, s, stt);
                    interpret(logs[i], pid, s, edt);
                    
                    if (lt == a && i == rt) {
                        sumt = rg;
                        res[spid] += rg - st;
                    } else {
                        sumt += edt - stt + 1;
                        res[pid] += edt - stt + 1 - st;
                    }
                }
            }
        }
        return sumt;
    }
    
    void interpret(string &log, int &pid, string &s, int &t) {
        pid = 0;
        int i;
        for (i = 0; i < log.length(); i ++) {
            if (log[i] == ':') break;
            pid = pid * 10 + log[i] - '0';
        }
        s = "";
        for (i = i + 1; i < log.length(); i ++) {
            if (log[i] == ':') break;
            s.push_back(log[i]);
        }
        t = 0;
        for (i = i + 1; i < log.length(); i ++) {
            t = t * 10 + log[i] - '0';
        }
    }
};