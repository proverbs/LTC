/*建图+bfs/最短路*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> to;
    vector<int> dis;
    vector<bool> vis;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int inf = 99999999;
        unordered_map<string, int> mp;
        int cnt = 0;
        mp[beginWord] = cnt ++;
        mp[endWord] = cnt ++;
        for (int i = 0; i < wordList.size(); i ++) {
            if (!mp.count(wordList[i])) mp[wordList[i]] = cnt ++;
        }
        vector<int> v;
        for (int i = 0; i < cnt; i ++) {
            to.push_back(v);
        }
        dis.resize(cnt, inf);
        vis.resize(cnt, 0);
        for (int i = 0; i < wordList.size(); i ++) {
            if (beginWord != wordList[i] && linkz(beginWord, wordList[i])) add(mp[beginWord], mp[wordList[i]]);
            for (int j = i + 1; j < wordList.size(); j ++) {
                if (wordList[i] != wordList[j] && linkz(wordList[i], wordList[j])) {
                    add(mp[wordList[i]], mp[wordList[j]]);
                    add(mp[wordList[j]], mp[wordList[i]]);
                }
            }
        }
        spfa(mp[beginWord]);
        return dis[mp[endWord]] == inf ? 0 : dis[mp[endWord]] + 1;
    }

    void add(int u, int v) {
        to[u].push_back(v);
    }

    void spfa(int s) {
        queue<int> q;
        q.push(s);
        vis[s] = true;
        dis[s] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = false;
            for (int i = 0; i < to[x].size(); i ++) {
                if (dis[to[x][i]] > dis[x] + 1) {
                    dis[to[x][i]] = dis[x] + 1;
                    if (!vis[to[x][i]]) {
                        vis[to[x][i]] = true;
                        q.push(to[x][i]);
                    }
                }
            }
        }
    }

    bool linkz(string& x, string& y) {
        int tt = 0;
        for (int i = 0; i < x.length(); i ++) {
            if (x[i] != y[i]) {
                tt ++;
                if (tt == 2) return false;
            }
        }
        return true;
    }
};

int main() {
    string st = "hit";
    string ed = "cog";
    vector<string> s;
    s.push_back("hot");
    s.push_back("dot");
    s.push_back("dog");
    s.push_back("lot");
    s.push_back("log");
    s.push_back("cog");
    cout << Solution().ladderLength(st, ed, s) << endl;
    return 0;
}