// toplogical sort

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edg(numCourses, vector<int>());
        vector<int> du(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i ++) {
            int v = prerequisites[i].first;
            int u = prerequisites[i].second;
            edg[u].push_back(v);
            du[v] ++;
        }
        
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) 
            if (!du[i]) q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int i = 0; i < edg[x].size(); i ++) {
                if (-- du[edg[x][i]] == 0) q.push(edg[x][i]);
            }
        }
        
        if (res.size() == numCourses) return res;
        return vector<int>();
    }
};