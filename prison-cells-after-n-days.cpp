// find the period of the cycle

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> states;
        unordered_map<int, int> mp;
        int state;
        int n, s;
        for (int i = 0; ; i ++) {
            state = to_state(cells);
            if (mp.count(state)) {
                n = i - mp[state];
                s = mp[state];
                break;
            } else {
                mp[state] = i;
                states.push_back(state);
            }
            cells = next_state(cells);
        }
        
        int resx;
        if (N <= s) resx = states[N];
        else resx = states[s + (N - s) % n];
        
        vector<int> res(8, 0);
        for (int i = 0; i < 8; i ++) {
            res[8 - i - 1] = 1 & (resx >> i);
        }
        return res;
    }
    
    int to_state(const vector<int>& cells) {
        int state = 0;
        for (int i = 0; i < 8; i ++) {
            if (cells[i]) state |= 1 << (8 - i - 1);
        }
        return state;
    }
    
    vector<int> next_state(const vector<int>& cells) {
        vector<int> res(8, 0);
        for (int i = 1; i < 7; i ++) {
            if (!(cells[i - 1] ^ cells[i + 1])) res[i] = 1;
        }
        return res;
    }
};