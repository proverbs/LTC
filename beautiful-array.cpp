// divide and conquer
// https://leetcode.com/problems/beautiful-array/discuss/186679/C%2B%2BJavaPython-Odd-%2B-Even-Pattern-O(N)

class Solution {
public:
    unordered_map<int, vector<int>> cache;
    vector<int> beautifulArray(int N) {
        if (cache.count(N)) return cache[N];
        vector<int>& ca = cache[N];
        ca = vector<int>();
        if (N == 1) ca.push_back(1);
        else {
            int odd = N + 1 >> 1;
            vector odd_part = beautifulArray(odd);
            vector even_part = beautifulArray(N - odd);
            for (int e: odd_part) ca.push_back(e * 2 - 1);
            for (int e: even_part) ca.push_back(e * 2);
        }
        return ca;
    }
};