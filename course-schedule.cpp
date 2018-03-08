/*graph, topsort, or dfs*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> v;
        vector<vector<int> > mp;
        for (int i = 0; i < numCourses; i ++) mp.push_back(v);
        vector<int> du(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i ++) {
            mp[prerequisites[i].first].push_back(prerequisites[i].second);
            du[prerequisites[i].second] ++;
        }
        vector<bool> vis(numCourses, 0);
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (du[i] == 0) q.push(i);
        }
        int tot = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            tot ++;
            for (int i = 0; i < mp[x].size(); i ++) {
                du[mp[x][i]] --;
                if (du[mp[x][i]] == 0) {
                    q.push(mp[x][i]);
                }
            }
        }
        return tot == numCourses;
    }
};