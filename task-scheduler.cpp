/*greed*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> lst, cnt;
        for (char x = 'A'; x <= 'Z'; x ++) {
            lst[x] = -n - 1;
            cnt[x] = 0;
        } 
        for (int i = 0; i < tasks.size(); i ++) {
            cnt[tasks[i]] ++;
        }
        int pos = 0;
        while (notEmpty(cnt)) {
            char c = getChar(lst, cnt, pos - n);
            if (c == '#') {
                pos ++;
                continue;
            }
            lst[c] = pos;
            cnt[c] --;
            pos ++;
        }
        return pos;
    }

    bool notEmpty(map<char, int>& cnt) {
        for (char x = 'A'; x <= 'Z'; x ++) {
            if (cnt[x] > 0) return true;
        } 
        return false;
    }

    char getChar(map<char, int>& lst, map<char, int>& cnt, int pos) {
        char c = '#';
        int cs = 0;
        for (char x = 'A'; x <= 'Z'; x ++) {
            if (lst[x] < pos && cnt[x] > cs) {
                c = x;
                cs = cnt[x];
            } 
        } 
        return c;
    }
};

int main() {
    vector<char> v;
    v.push_back('A');v.push_back('A');v.push_back('A');
    v.push_back('B');v.push_back('B');v.push_back('B');
    cout << Solution().leastInterval(v, 2) << endl;
    return 0;
}