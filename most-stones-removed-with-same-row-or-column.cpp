
// Connected stones can be reduced to 1 stone,
// the maximum stones can be removed = stones number - islands number.
// DSU
class Solution {
public:
    vector<int> fa;
    int removeStones(vector<vector<int>>& stones) {
        int cnt = 0;
        unordered_map<int, int> row, col;
        for (vector<int>& v: stones) {
            if (!row.count(v[0])) row[v[0]] = cnt ++;
            if (!col.count(v[1])) col[v[1]] = cnt ++;
        }
        
        fa.clear();
        for (int i = 0; i < cnt; i ++) 
            fa.push_back(i);
        
        for (vector<int>& v: stones) {
            int x = row[v[0]];
            int y = col[v[1]];
            if (findfa(x) != findfa(y)) {
                fa[findfa(x)] = findfa(y);
            }
        }
        
        int res = stones.size();
        for (int i = 0; i < cnt; i ++)
            if (fa[i] == i) res --;
        return res;
    }
    
    int findfa(int x) {
        if (x != fa[x]) return fa[x] = findfa(fa[x]);
        return x;
    }
};

// a wrong approach using greedy algorithm
// a counter example: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> col_cnt, row_cnt;
        vector<bool> vis(stones.size(), true);
        for (vector<int>& stone: stones) {
            if (col_cnt.count(stone[1])) col_cnt[stone[1]] ++;
            else col_cnt[stone[1]] = 1;
            if (row_cnt.count(stone[0])) row_cnt[stone[0]] ++;
            else row_cnt[stone[0]] = 1;
        }
        
        int res = 0;
        while (true) {
            int idx = -1, ict = 3;
            for (int j = 0; j < stones.size(); j ++) {
                if (!vis[j]) continue;
                int ct = 0;
                if (row_cnt[stones[j][0]] > 1) ct ++;
                if (col_cnt[stones[j][1]] > 1) ct ++;
                if (ct > 0 && ct < ict) {
                    idx = j;
                    ict = ct;
                }
            }
            if (idx == -1) break;
            
            vis[idx] = false;
            row_cnt[stones[idx][0]] --;
            col_cnt[stones[idx][1]] --;
            res ++;
            // cout << idx << endl;
        }
        
        return res;
    }
};